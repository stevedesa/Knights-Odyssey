/** *****************************************************************
* @file
*
* @brief Only includes recursive function that computes the Knight's 
* Tour.
*******************************************************************/
#include "thpe13.h"

/** ***************************************************************************
 * @author Steve Nathan de Sa
 *
 * @par Description
 * This function finds the tour of the knight by checking which unused, inbound
 * spaces the knight can go to using a recursive algorithm to make sure the 
 * knight stays in a valid space on the chessboard and only travels to 
 * untraversed spots on the board. It accordingly marks the spots on the board
 * in the order of which the knight travels, based on a predefined set of 
 * positions the knight can travel to.
 *
 * @param[in, out]  matrix - contains matrix data of chessboard.
 * @param[in]       size - stores size of board.
 * @param[in]       row - stores which row knight is on.
 * @param[in]       col - stores which col knight is on.
 * @param[in]       value - stores value of knights journey.
 *
 * @returns true if knights tour is successful, false if knight isn't able to 
 * traverse properly throughout the board.
 * 
 * @par Example
 * @verbatim
   int value = 1;
   int boardsize = 8;
   int rows = 0;
   int cols = 0;
   int** matrix;

   bool found = findTour(matrix,boardsize,rows,cols,value);
   //Matrix will contain knights tour if found is true
   @endverbatim
 *****************************************************************************/
bool findTour(int**& matrix, int size, int row, int col, int value)
{
    int i;

    int currrow, currcol;

    int knightx[8] = { -2, -1, 1, 2, 2, 1, -1, -2 }; //x-axis coords

    int knighty[8] = { 1, 2, 2, 1, -1, -2, -2, -1 }; //y-axis coords

    if ( value > size * size ) //max_value
    {
        return true;
    }

    for ( i = 0; i < 8; i++ )
    {
        currrow = row + knightx[i];
        currcol = col + knighty[i];

        if ( isValid(matrix, currrow, currcol) == true )
        {
            matrix[currrow][currcol] = value;

            if (findTour(matrix, size, currrow, currcol, value + 1) == true)
            {
                return true;
            }

            matrix[currrow][currcol] = 0; //backtrack
        }
    }

    return false;
}

/** ***************************************************************************
 * @author Steve Nathan de Sa
 *
 * @par Description
 * This function checks if the spot at rows, cols is unused.
 *
 * @param[in, out]  matrix - contains matrix data.
 * @param[in]       rows - stores current row location.
 * @param[in]       cols - stores current col location.
 *
 * @returns true if spot was unused by knight on true, false if spot was 
 * previously used by knight.
 * 
 * @par Example
 * @verbatim
   int rows = 0;
   int cols = 0;
   int** matrix;

   bool found = isValid(matrix, rows, cols);
   //If found = true, spot (rows, cols) was unused by knight on tour
   @endverbatim
 *****************************************************************************/
bool isValid(int**& matrix, int rows, int cols)
{
    int x = rows;
    int y = cols;

    if ( matrix[x][y] == 0 ) //Unused Spot
    {
        return true;
    }
    else
    {
        return false;
    }
}