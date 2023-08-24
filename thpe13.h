/** *****************************************************************
* @file
*
* @brief Contains function prototypes of the program.
*******************************************************************/
/** **************************************************************************
 * @mainpage Take Home Programming Exam 3 - The Knight’s Tour
 *
 * @section course_section Course Information
 *
 * @author Steve Nathan de Sa
 *
 * @par Professor:
 *         Roger Schrader
 *
 * @par Course:
 *         CSC215 - M002 - Programming Techniques
 *
 * @par Location:
 *         Classroom Building CB327
 *
 * @date Due April 24, 2023
 *
 * @section program_section Program Information
 *
 * @details
 * The purpose of this program is to find the tour of a knight on a chessboard
 * using a brute force recursive algorithm. A knight's tour is a sequence of moves 
 * of a knight on a chessboard such that the knight visits every square once and 
 * only once. So given the size of the board and a starting position it shows
 * how the knight would move to complete its tour. Its starting spot would be labeled 
 * with a 1 and the next move would be labeled as 2 and so on. If the n was equal to 8,
 * the final step would be 64 (8x8).
 *
 * There are 2 ways to run the program, both via command line arguments. If one arg is 
 * given, the Knight's Tour is calculated according to instructions given by the user
 * through the terminal. Options are displayed to the user from which the user can 
 * accordingly select his/her preferences. Option 2 takes information of multiple tours
 * from a file and outputs the tours from this information to a specific output file.
 *
 * @section compile_section Compiling and Usage
 *
 * @par Compiling Instructions:
 *      none - a straight compile and link with no external libraries.
 *
 * @par Usage:
   @verbatim
   thpe13.exe [tourfile]

   tourfile - name of a text file containing puzzles for the knight's tour
   @endverbatim
*
* @section todo_bugs_modification_section Todo, Bugs, and Modifications
* 
* @bug No Bugs!
* 
* @todo Project Complete!
* 
* @par Modifications and Development Timeline:
* Link to my Gitlab commits. To view <a target="_blank"
* href="https://gitlab.cse.sdsmt.edu/101124071/csc215s23programs/-/commits/main?ref_type=heads">click here</a>
 *****************************************************************************/
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

//FILE OPTIONS.CPP

void Option1(); //does option 1

void Option2(ifstream& fin); //does option 2

void openOPFile(ofstream& fout); //opens file for output of data

//FILE MEMORY.CPP

void allocarray(int**& array, int n); //allocate memory

void freearray(int**& array, int n); //delete memory

//FILE TOUR.CPP

void Tour(ostream& xout, int num, int boardsize, int rows, int cols); //tour function

void assignMatrix(int**& matrix, int boardsize); //assign matrix

void tourPrint(ostream& xout, int num, bool found, int** matrix, 
     int boardsize, int rows, int cols); //prints tour

//FILE SOLVE.CPP

bool findTour(int**& matrix, int size, int row, int col, int value); //find tour

bool isValid(int**& matrix, int rows, int cols); //checks if knight's tour is valid