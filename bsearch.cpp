/* Filename:  bsearch.cpp

   Author:  Br. David Carlson

   Date:  January 19, 1998

   Revised:  Jun 25, 2000; Nov 28, 2001; Feb 2, 2014

   This program creates an array of 100 sorted integers, prints them,
   and then allows the user to repeatedly look up items using binary
   search.  The result of each search (array index where the item was
   found or a not found message) is printed on the screen.

   Tested with:
      Microsoft Visual C++ 2012
      g++ under Linux
*/

#include <cstdlib>    // needed for srand, rand, and tolower functions
#include <ctime>      // needed for time function
#include <cctype>     // for tolower function
#include <iostream>
#include <iomanip>   // needed for setw
using namespace std;


const int MaxArray = 100;

typedef int IntArrayType[MaxArray];


// Function prototypes:

int BinarySearch(IntArrayType IntArray, int Low, int High, int Target);

void LoadArray(IntArrayType IntArray, int Count);

void PrintArray(IntArrayType IntArray, int Count);

void DoSearches(IntArrayType IntArray, int Count);


/* Given:   IntArray   Array of integers.
            Low        The low index of the range of integers to search.
            High       The top index of the range of integers to search.
            Target     The integer for which to search.
   Task:    To do a binary search for Target in the specified range of IntArray.
   Return:  In the function name, return the index of where Target was found or
            -1 if it was not found.
*/
int BinarySearch(IntArrayType IntArray, int Low, int High, int Target)
{
    int Mid;

    while (Low <= High)
    {
        Mid = (Low + High) / 2;

        if (IntArray[Mid] == Target)   // we found it
            return Mid;
        else if (IntArray[Mid] < Target)   // need to search the right side
            Low = Mid + 1;
        else                           // search the left side
            High = Mid - 1;
    }

    return -1;   // If we reach here, Target was not found.
}


/* Given:  IntArray   Array of integers, with the data stored at indices
                      0 through Count - 1.
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
        if (k % 15 == 14)
            cout << endl;
    }

    cout << endl;
}


/* Given:   Count     The number of integers to be placed into IntArray.
   Task:    To place Count sorted integers into IntArray.
   Return:  IntArray  The array of sorted integers.
*/
void LoadArray(IntArrayType IntArray, int Count)
{
    int k;

    srand(time(NULL));
    IntArray[0] = 1;
    for (k = 1; k < Count; k++)
        IntArray[k] = IntArray[k - 1] + (10.0 * rand()) / RAND_MAX + 1;
}


/* Given:  IntArray   Array of integers, with the data stored at indices
                      0 through Count - 1.
           Count      The number of integers in IntArray.
   Task:   To allow the user to do as many searches as desired for
           particular items, with the result of each search printed on
           the screen.
   Return: Nothing.
*/
void DoSearches(IntArrayType IntArray, int Count)
{
    int Num, Position;
    char Reply;

    do
    {
        cout << "Enter number to search for: ";
        cin >> Num;
        Position = BinarySearch(IntArray, 0, Count - 1, Num);

        if (Position == -1)
            cout << "Not found" << endl;
        else
            cout << "Found in position " << Position << endl;

        cout << endl << "Do another search (y/n)? ";
        cin >> Reply;
        Reply = tolower(Reply);   // convert to lower case
    }
    while (Reply == 'y');
}


int main(void)
{
    IntArrayType IntArray;

    LoadArray(IntArray, MaxArray);
    PrintArray(IntArray, MaxArray);
    DoSearches(IntArray, MaxArray);

    return 0;
}
