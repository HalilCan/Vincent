/* Filename:  select.cpp

   Author:  Br. David Carlson

   Date:  January 19, 1997

   Revised:  May 25, 2000; Nov 28, 2001; Feb 2, 2014

   This program creates an array of 100 random integers and prints it
   (just to see the data).  The program then sorts and prints this array,
   asks the user for an integer to find, and does a binary search
   for this integer in the sorted array.  The result (array index where
   it was found or a not found message) is printed on the screen.

   This program is essentially the same as the bubble.cpp program except
   that it uses a selection sort instead of a bubble sort.

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

void SelectionSort(IntArrayType IntArray, int Count);


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


/* Given:  DataArray  The array of integers to be sorted, with the data
                      running from index 0 to index Count - 1.
           Count      The number of items in IntArray.
   Task:   To sort IntArray into ascending order using selection sort.
   Return: DataArray  The sorted array.
*/
void SelectionSort(IntArrayType DataArray, int Count)
{
    int i, k, Min, MinIndex;

    for (i = 0; i < Count - 1; i++)
    {
        // Find the minimum from index i to Count - 1.
        // Assume it's the first item until we know better.
        Min = DataArray[i];
        MinIndex = i;

        for (k = i + 1; k < Count; k++)
            if (DataArray[k] < Min)   // We've found a better minimum
            {
                Min = DataArray[k];
                MinIndex = k;
            }

        if (MinIndex != i)   // swap DataArray[i] and the minimum
        {
            DataArray[MinIndex] = DataArray[i];
            DataArray[i] = Min;
        }
    }
}


/* Given:  MinSize  The minimum value that the user can enter.
           MaxSize  The maximum value that the user can enter.
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

    SelectionSort(IntArray, Size);

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

    cout << endl << "Enter the letter g to go on: ";
    cin >> Reply;

    return 0;
}
