/* Filename:  seqsrch.cpp

   Author:  Br. David Carlson

   Date:  January 19, 1998

   Revised:  June 25, 2000; November 28, 2001

   This program creates an array of 100 random integers, prints them, asks
   the user for an integer to search for, and does a sequential search
   for this integer in the array.  The result (the array index where it
   was found or a not found message) is printed on the screen.

   Tested with:
      Microsoft Visual C++ 6.0
      Microsoft Visual C++ .NET
      g++ under Linux
*/

#include <cstdlib>   // needed by srand and rand functions
#include <ctime>     // needed by time function
#include <iostream>
#include <iomanip>  // needed by setw
using namespace std;


const int ArrayMax = 100;

typedef int IntArrayType[ArrayMax];


// Function prototypes:

int SequentialSearch(IntArrayType IntArray, int Count, int Target);

void LoadArray(IntArrayType IntArray, int Count);

void PrintArray(IntArrayType IntArray, int Count);


/* Given:   IntArray   Array of integers, containing data from index 0
                       to index Count - 1.
            Count      The number of items in IntArray.
            Target     The integer for which to search.
   Task:    To do a sequential search for Target in the specified range
            of IntArray.
   Return:  In the function name, return the index of where Target was
            found or -1 if it was not found.
*/
int SequentialSearch(IntArrayType IntArray, int Count, int Target)
{
    int k;

    for (k = 0; k < Count; k++)
        if (IntArray[k] == Target)
            return k;

    return -1;   // If reach here, Target was not found.
}


/* Given:  IntArray   Array of integers, containing data from index 0
                      to index Count - 1.
           Count      The number of integers in IntArray.
   Task:   To print the integers from IntArray, with up to 15 per line.
   Return: Nothing.
*/
void PrintArray(IntArrayType IntArray, int Count)
{
    int k;

    for (k = 0; k < Count; k++)
    {
        cout << setw(5) << IntArray[k];
        if (k % 15 == 14)   // check the remainder after division by 15
            cout << endl;
    }

    cout << endl;
}


/* Given:   Count     The number of integers to be placed into IntArray.
   Task:    To place Count random integers into IntArray, with the
            random integers all fitting between 0 and 1000.
   Return:  IntArray  The array of random integers.
*/
void LoadArray(IntArrayType IntArray, int Count)
{
    int k;

    srand(time(NULL));  // seed the random number generator

    for (k = 0; k < Count; k++)
        IntArray[k] = (1000.0 * rand()) / RAND_MAX;
    // Note that rand() returns a random integer between 0 and RAND_MAX.
}


int main(void)
{
    IntArrayType IntArray;
    int Num, Position;

    LoadArray(IntArray, ArrayMax);
    PrintArray(IntArray, ArrayMax);

    cout << "Enter the number to search for: ";
    cin >> Num;
    Position = SequentialSearch(IntArray, ArrayMax, Num);

    if (Position == -1)
        cout << "Not found" << endl;
    else
        cout << "Found in position " << Position << endl;

    return 0;
}

