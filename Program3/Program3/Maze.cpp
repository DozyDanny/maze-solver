/*
* Credit: The method for dynamically allocated arrays were found from this website:
* https://www.techiedelight.com/dynamic-memory-allocation-in-c-for-2d-3d-array/
* So those are not made by me. Everything else about the implementation
* of the 2D arrays are written by me.
*/
#include "Maze.h"
#include <vcclr.h>
#include <fstream>

Maze::Maze(Panel^ drawingPanel, ifstream& ifs)
{
   // Initialize some variables, and read in the first two numbers
   valid = true;
   panel = drawingPanel;
   solved = nullptr;
   orig = nullptr;
   ifs >> width >> height;

   // Quickly check to make sure the file doesn't exceed the number limit
   if (width > MAXSIZE || height > MAXSIZE)
      valid = false;

   // If it's not too big, we can start by
   // dynamically create an array of pointers of size "height"
   orig = new char * [width];

   // dynamically allocate memory of size "width" for each row
   for (int i = 0; i < width; i++)
      orig[i] = new char[height];

   // Now I should be able to assign values to the allocated memory. Hooray!

   // 1: read in the map
   for (int i = 0; i < height; i++)
      for (int j = 0; j < width; j++)
      {
         ifs >> orig[j][i];

         // check to make sure the input is normal. If it has garbage, then it is invalid!
         if (orig[j][i] != 'O' && orig[j][i] != '+' && orig[j][i] != 'S' &&
                                    orig[j][i] != 'E' && orig[j][i] != 'X')
            valid = false;
      }
   // 2: Set valid to true if there are no invalid charaters found and the size of the map is valid
   
}

void Maze::Solve(int xPixel, int yPixel)
{
   // Divide the coordinates of the mouse to by the Cell Size to see which cell the user clicked
   int y = xPixel / CELLSIZE;
   int x = yPixel / CELLSIZE;

   // Initialize free to false
   free = false;  

   // dynamically create an array of pointers of size "height"
                  
   solved = new char* [width];

   // dynamically allocate memory of size "width" for each row
   for (int i = 0; i < width; i++)
      solved[i] = new char[height];

   // Copy over the original maze to the solved version of the maze before we do any solving
   for (int i = 0; i < height; i++)
      for (int j = 0; j < width; j++)
         solved[j][i] = orig[j][i];

   // Quickly double check that the user didn't accidentally click a border
   if (solved[y][x] == '+')
   {
      free = false;
      return;
   }
   // If the user clicked the winning box straight away, we don't need to do all the recusion
   else if (solved[y][x] == 'E')
   {
      free = true;
      return;
   }
   // If the user clicked a valid box, we can begin the solving process
   else
   {
      solved[y][x] = 'S';
      RecSolve(x, y);
   }
   
}

void Maze::RecSolve(int row, int col)
{
   // If the exit was found, we are free!
   if (solved[col][row] == 'E')
   {
      free = true;
      return;
   }
   // This is the main recursion section, it loops through each open box until all have been found
   else if (solved[col][row] == 'O' && col < MAXSIZE && row < MAXSIZE && row >= 0 && col >= 0)
   {
      solved[col][row] = 'X';
      // the if statements are just to make sure the RecSolve doesn't jump into a space that doesn't exist in the array (since they are dynamically allocated)
      if (row != height - 1)
         RecSolve(row + 1, col);
      if (row != 0)
         RecSolve(row - 1, col);
      if (col != width - 1)
         RecSolve(row, col + 1);
      if (col != 0)
         RecSolve(row, col - 1);
   }
   // this case only happens once, at the start of the process.
   else if (solved[col][row] == 'S' && row >= 0 && col >= 0)
   {
      if (row != height - 1)
         RecSolve(row + 1, col);
      if (row != 0)
         RecSolve(row - 1, col);
      if (col != width - 1)
         RecSolve(row, col + 1);
      if (col != 0)
         RecSolve(row, col - 1);
   }
}

void Maze::Show(char** cells)
{
   // this changes the panel size so you only see the boxes that exist in the current instance
   panel->Height = height * CELLSIZE;
   panel->Width = width * CELLSIZE;

   // Loop through each character in the array and draw a box for the corresponding character
   for (int i = 0; i < width; i++)
   {
      for (int j = 0; j < height; j++)
      {
         Graphics^ graphic = panel->CreateGraphics();

         // used to fill the rectangle with a color
         Brush^ color;
         // define the color of the brush
         if (cells[i][j] == 'O')
            color = gcnew SolidBrush(Color::White);
         else if (cells[i][j] == '+')
            color = gcnew SolidBrush(Color::Black);
         else if (cells[i][j] == 'E')
            color = gcnew SolidBrush(Color::Green);
         else if (cells[i][j] == 'S')
            color = gcnew SolidBrush(Color::Red);
         else if (cells[i][j] == 'X')
            color = gcnew SolidBrush(Color::Blue);
         else
            color = gcnew SolidBrush(Color::Pink); // This should never appear, it's just for debugging purposes

         graphic->FillRectangle(color, Rectangle(i * CELLSIZE, j * CELLSIZE, CELLSIZE, CELLSIZE));
      }
   }
}
