/* Filename:  bubble.cpp

   Author:  Br. David Carlson

   Date:  January 19, 1998

   Revised:  Jun 25, 2000; Nov 28, 2001, Feb 2, 2014

   This program creates an array of 100 random integers and prints it
   (just to see the data).  The program then sorts and prints this array,
   asks the user for an integer to find, and does a binary search
   for this integer in the sorted array.  The result (array index where
   it was found or a not found message) is printed on the screen.

   Tested with:
      Microsoft Visual C++ 2012
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

int GetSize(int MinSize, int MaxSize);

int BinarySearch(IntArrayType IntArray, int Low, int High, int Target);

void LoadArray(IntArrayType IntArray, int Count);

void PrintArray(IntArrayType IntArray, int Count);

void BubbleSort(IntArrayType IntArray, int Count);


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


/* Given:  IntArray   Array of integers, with data from index 0 to
                      index Count - 1.
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
    for (k = 0; k < Count; k++)
        IntArray[k] = (1000.0 * rand()) / RAND_MAX;
}


/* Given:  First   An integer.
           Second  An integer.
   Task:   To swap the values in First and Second.
   Return: First
           Second
   Note:   This is an "inline" function.  That means that the normal
           function call and return mechanism is not used.  Instead a copy
           of the function code replaces the function call.  This is
           faster and is appropriate for very short functions (so as to
           not add greatly to the program's length by inserting the same
           code everywhere where the function is called).  An inline
           function can only be used AFTER this section where it is
           defined; function prototypes are not used.
*/
inline void Swap(int & First, int & Second)
{
    int Temp;

    Temp = First;
    First = Second;
    Second = Temp;
}


/* Given:  IntArray   The array of integers to be sorted, with data
                      from index 0 to index Count - 1.
           Count      The number of items in IntArray.
   Task:   To bubblesort IntArray into ascending order.
   Return: IntArray   The sorted array.
*/
void BubbleSort(IntArrayType IntArray, int Count)
{
    int Top, k;
    bool Done;   // boolean variable, takes values true, false

    Top = Count - 1;
    Done = false;

    while ((! Done) && (Top > 0))
    {
        Done = true;   // until we know better
        for (k = 0; k < Top; k++)
            if (IntArray[k] > IntArray[k + 1])
            {
                Done = false;   // because we are making a swap
                Swap(IntArray[k], IntArray[k + 1]);
            }
        Top--;
    }
}

/* For use of an index array, see:
 * if (A[Index[k]] > A[Index[k + 1]])
   {
   Done = false;
   Swap(Index[k], Index[k + 1]);
   }
*/


/* Given:  MinSize  The minimum allowable size.
           MaxSize  The maximum allowable size.
   Task:   To prompt the user for an integer size from MinSize to
           MaxSize and to insist on getting only that.
   Return: The user's number in the function name.
*/
int GetSize(int MinSize, int MaxSize)
{
    int Num;

    cout << "Enter the size for the array, using an integer from "
         << MinSize << " to " << MaxSize << ":  ";
    cin >> Num;

    while ((Num < MinSize) || (Num > MaxSize))
    {
        cout << "Re-enter.  Use an integer from " << MinSize << " to "
             << MaxSize << ":  ";
        cin >> Num;
    }

    return Num;
}


int main(void)
{
    IntArrayType IntArray;
    int Num, Position, Size;
    char Reply;

    Size = GetSize(2, ArrayMax);
    LoadArray(IntArray, Size);

    cout << endl << "The original unsorted array:" << endl;
    PrintArray(IntArray, Size);

    BubbleSort(IntArray, Size);

    // A simple way to pause output:
    cout << endl << "Enter the letter g to go on: ";
    cin >> Reply;
    cout << endl << "The sorted array:" << endl;
    PrintArray(IntArray, Size);

    cout << endl << "Enter a number to search for: ";
    cin >> Num;
    Position = BinarySearch(IntArray, 0, Size - 1, Num);

    if (Position == -1)
        cout << "Not found" << endl;
    else
        cout << "Found in position " << Position << endl;

    return 0;
}
