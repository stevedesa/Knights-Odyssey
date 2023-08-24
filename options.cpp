/** *****************************************************************
* @file
*
* @brief Accordingly does algorithms for Options 1 and 2.
*******************************************************************/
#include "thpe13.h"

/** ***************************************************************************
 * @author Steve Nathan de Sa
 *
 * @par Description
 * This function runs the algorithm for option 1 of the program. It uses switch 
 * cases to keep on calling the options of the program, for the user to edit, 
 * until the user decides to call the tour function which prints out the tour 
 * and exits the program. It gives users the option to change the board size, 
 * or change the starting point of the tour. It also makes sure that all 
 * proceedings are withing appropriate bounds and checks to prevent overstepping 
 * of bounds. After the user is satisfied with it's requirements, it can set the
 * function to call the tour function, to print out the knights tour.
 *
 * @par Example
 * @verbatim
   Option1(); //Runs Algorithm for Option 1
   @endverbatim
 *****************************************************************************/
void Option1()
{
    int choice;
    int tempsize, boardsize = 8;
    int temprow, tempcol, rows = 7, cols = 7;

    do
    {
        cout << "1) Change board size from " << boardsize << "x" << boardsize 
             << endl;

        cout << "2) Change starting location from (" << rows << ", " << cols 
             << ")" << endl;

        cout << "3) Exit and solve tour" << endl;

        cout << "Enter Choice: ";
        cin >> choice;
        cout << endl;

        if ( choice > 3 || choice < 1 )
        {
            choice = 4; //INVALID
        }

        switch (choice)
        {
        case 1:
            cout << "Enter the size of the NxN Board (>3): ";
            cin >> tempsize;
            cout << endl;

            if ( tempsize > 3 && rows < tempsize && cols < tempsize )
            {
                boardsize = tempsize;
            }

            else
            {
                cout << "Board size is invalid" << endl;
                cout << "\n";
            }

            break;

        case 2:
            cout << "Enter Starting Coordinates (row, col): ";
            cin >> temprow >> tempcol;
            cout << endl;

            if ( temprow < boardsize && tempcol < boardsize )
            {
                rows = temprow;
                cols = tempcol;
            }

            else
            {
                cout << "Invalid starting coordinates" << endl;
                cout << "\n";
            }

            break;

        case 3:
            Tour( cout, 1, boardsize, rows, cols );
            break;

        case 4:
            cout << "Invalid option" << endl;
            cout << "\n";
        }
    } 
    while (choice != 3);
}

/** ***************************************************************************
 * @author Steve Nathan de Sa
 *
 * @par Description
 * This function runs the algorithm for option 2 of the program. It reads all of
 * the information to the file, which is the boardsize, rows and columns of data,
 * and for each set of values provided, it call the tour function to appropriately
 * output the data to the output file using the fout stream defined inside the file.
 *
 * @param[in, out] fin - manages file input stream of opened file.
 * 
 * @par Example
 * @verbatim
   ifstream fin.
   Option2(fin); //Runs Algorithm for Option 2
   @endverbatim
 *****************************************************************************/
void Option2(ifstream& fin)
{
    int count = 0;
    int i = 0;
    int num = 0;
    int* storage = new (nothrow) int[10000];

    while ( fin >> storage[count] ) //reads all data from file
    {
        count++;
    }

    ofstream fout;
    openOPFile(fout);

    while ( i < count )
    {
        int boardsize = storage[i];
        i++;
        int rows = storage[i];
        i++;
        int cols = storage[i];
        i++;

        num++;
        Tour(fout, num, boardsize, rows, cols); //tour fn for each case
    }

    delete[] storage; //frees up allocated memory
}

/** ***************************************************************************
 * @author Steve Nathan de Sa
 *
 * @par Description
 * Opens the output file "Solutions.tours" for output of the tours. The file
 * on opening deletes all previous data contained in the file.
 * 
 * @param[in, out] fout - manages file output stream of opened file.
 *
 * @par Example
 * @verbatim
   ofstream fout.
   OpenOPFile(fout); 
   //Opens output file "Solution.tours" and assigns it to fout stream
   @endverbatim
 *****************************************************************************/
void openOPFile(ofstream& fout)
{
    string filename = "Solutions.tours";

    fout.open( filename ,ios::trunc ); //clears o/p file before o/p

    if ( !fout.is_open() )
    {
        cout << "Unable to open the file: " << filename << endl;
    }
}