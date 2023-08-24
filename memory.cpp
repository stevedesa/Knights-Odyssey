/** *****************************************************************
* @file
*
* @brief Handles memory allocation and deletion for the 2d dynamic
* arrays.
*******************************************************************/
#include "thpe13.h"

//2D ARRAY ALLOCATION
/** ***************************************************************************
 * @author Steve Nathan de Sa
 *
 * @par Description
 * This function accepts a 2d pointer array and assigns 2d memory
 * to the array of n rows and columns, based on the number of rows and
 * columns provided by the user. The output matrix is a square matrix
 *
 * @param[in, out]  array - accepts 2d pointer array, to assign dynamic memory.
 * @param[in]       n - number of rows and columns of memory to assign.
 *
 * @par Example
 * @verbatim
   int** array;
   int n = 5; //number of rows and columns
   allocarray(array, n);
   //now array is a dynamic 2d array of n rows and columns;
   @endverbatim
 *****************************************************************************/
void allocarray(int**& array, int n)
{
    int i;

    array = new (nothrow) int * [n];

    if ( array == nullptr )
    {
        cout << "Unable to allocate memory" << endl;
        delete[] array;
        exit(0);
    }

    for ( i = 0; i < n; i++ )
    {
        array[i] = new (nothrow) int[n];

        if ( array[i] == nullptr )
        {
            cout << "Unable to allocate memory" << endl;
            freearray(array, i);
            exit(0);
        }
    }
}

//2D ARRAY DELETION
/** ***************************************************************************
 * @author Steve Nathan de Sa
 *
 * @par Description
 * This function accepts an initiated 2d dynamic pointer array and clears its
 * data memory.
 *
 * @param[in, out]  array - accepts 2d pointer array, to erase dynamic memory.
 * @param[in]       n - number of rows of memory in file.
 *
 * @par Example
 * @verbatim
   pixel** array;
   int n = rows; //number of rows and columns
   allocarray(array, n);
   //now array is a dynamic 2d array of n rows and columns
   freearray(array, n);
   //now array has its memory freed up, with memory erased
   @endverbatim
 *****************************************************************************/
void freearray(int**& array, int n)
{
    int i;

    if ( array == nullptr )
    {
        return;
    }

    for ( i = 0; i < n; i++ )
    {
        delete[] array[i];
    }

    delete[] array;
}
