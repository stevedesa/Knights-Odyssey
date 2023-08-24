/** *****************************************************************
* @file
*
* @brief Contains main function of the program. It handles the command
* line arguments and assigns further instructions based on them.
*******************************************************************/
#include "thpe13.h"

/** **********************************************************************
 *  @author Steve Nathan de Sa
 *
 *  @par Description
 *  It handles the command line arguments and assigns further instructions 
 *  based on them.
 *
 *  @param[in] argc Number of command line arguments from user.
 *  @param[in] argv String values of command line arguments
 *
 * @returns Returns a 0 upon correct runtime, returns error message and usage
 *          statement upon error in files or command line arguments.
 *
 *  @par Example
 *  @verbatim
    Usage: thpe13.exe [tourfile]
    @endverbatim
 ************************************************************************/
int main(int argc, char *argv[])
{
    if ( argc == 1 )
    {
        Option1(); //do option 1
    }

    else if ( argc == 2 )
    {
        ifstream fin;
        string filename = argv[1]; 

        fin.open(filename);

        if ( !fin.is_open() )
        {
            cout << "Unable to open the file: " << filename << endl;
        }

        else
        {
            Option2(fin); //do option 2
        }
    }

    else
    {
        cout << "Usage: thpe13.exe [tourfile]" << endl;
        cout << "       tourfile - name of a text file containing puzzles ";
        cout << "for the knight's tour" << endl;
    }

    return 0;
}   