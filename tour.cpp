/** *****************************************************************
* @file
*
* @brief Tour function handles all the functions that go into finding 
* the Knight's Tour. It assigns the matrix, finds the tour, prints the
* tour and frees up allocated memory.
*******************************************************************/
#include "thpe13.h"

/** ***************************************************************************
 * @author Steve Nathan de Sa
 *
 * @par Description
 * This function calls other functions to complete the knights tour based on
 * the parameters given by the user. It follows the steps of first assigning
 * dynamic memory, finding the tour of the knight, prints the tour and then
 * frees up the assigned memory.
 *
 * @param[in, out]  xout - contains appropriate stream for output.
 * @param[in]       num - contains tour number #.
 * @param[in]       boardsize - contains size of board.
 * @param[in]       rows - contains number of rows.
 * @param[in]       cols - contains number of cols.
 *
 * @par Example
 * @verbatim
   ifstream fin;
   int num = 1;
   int boardsize = 8;
   int rows = 0;
   int cols = 0;

   Tour(fin,num,boardsize,rows,cols);
   //Outputs Tour #1 to fin stream
   @endverbatim
 *****************************************************************************/
void Tour(ostream& xout, int num, int boardsize, int rows, int cols)
{
    //STEP 1: Assign Dynamic Matrix
    int** matrix;
    assignMatrix(matrix, boardsize);

    //STEP 2: Find Tour
    int value = 1;
    matrix[rows + 2][cols + 2] = value; //Initiate starting posn
    value++;
    bool found = findTour(matrix, boardsize, rows + 2, cols + 2, value);

    //STEP 3: Print Tour
    tourPrint(xout, num, found, matrix, boardsize, rows, cols);

    //STEP 4: Clear Dynamic Matrix
    freearray(matrix, boardsize + 4);
}

/** ***************************************************************************
 * @author Steve Nathan de Sa
 *
 * @par Description
 * This function assigns memory to the array mimicking a chessboard. it assigns
 * 2 extra rows at each side and assigns the extra space to -1 whilst the actual
 * part of the board remains at 0. This is done to make sure the knight doesnt
 * cross the boundaries of the board.
 *
 * @param[in, out]  matrix - contains matrix data.
 * @param[in]       boardsize - contains size of board.
 *
 * @par Example
 * @verbatim
   int** matrix;
   assignMatrix(matrix, boardsize);
   //Assigns Matrix of size (boardsize+4)*(boardsize+4)
   @endverbatim
 *****************************************************************************/
void assignMatrix(int**& matrix, int boardsize)
{
    int i, j;

    int size = boardsize + 4; //+4 to create board bounds

    allocarray(matrix, size);

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (i == 0 || i == 1 || i == size - 1 || i == size - 2)
            {
                matrix[i][j] = -1;
            }

            else if (j == 0 || j == 1 || j == size - 1 || j == size - 2)
            {
                matrix[i][j] = -1;
            }

            else
            {
                matrix[i][j] = 0;
            }
        }

    }
}

/** ***************************************************************************
 * @author Steve Nathan de Sa
 *
 * @par Description
 * This function prints the tour of the knight to the appropriate stream. if
 * the tour wasn't successful, it'll output to the stream that there was no
 * solution possible for the tour.
 *
 * @param[in, out]  xout - contains appropriate stream for output.
 * @param[in]       num - contains tour number #.
 * @param[in]       found - contains if tour was successful or not.
 * @param[in, out]  matrix - contains matrix data.
 * @param[in]       boardsize - contains size of board.
 * @param[in]       rows - contains number of rows.
 * @param[in]       cols - contains number of cols.
 *
 * @par Example
 * @verbatim
   ifstream fin;
   int num = 1;
   int boardsize = 8;
   int rows = 0;
   int cols = 0;
   Tour(fin,num,boardsize,rows,cols);
   //Outputs Tour #1 to fin stream
   @endverbatim
 *****************************************************************************/
void tourPrint(ostream& xout, int num, bool found, int** matrix,
    int boardsize, int rows, int cols)
{
    int i, j;

    xout << "Tour # " << num << endl;
    xout << "     " << boardsize << "x" << boardsize;
    xout << " starting at (" << rows << ", " << cols << ")";
    xout << endl;

    if (found == true) //complete tour
    {
        for (i = 2; i < boardsize + 2; i++)
        {
            xout << "    ";
            for (j = 2; j < boardsize + 2; j++)
            {
                xout << setw(3) << right << matrix[i][j];
            }
            xout << endl;
        }
        xout << "\n";
    }

    else //incomplete tour
    {
        xout << "     " << "No solutions for this case" << endl;
        xout << "\n";
    }
}