/* Filename:  area2.cpp

   Author:  Br. David Carlson
            Br. Isidore Minerd

   Date:  January 4, 2000

   Modified:  June 26, 2000; August 19, 2001; July 16, 2009

   This program asks the user to enter the length and width of a
   rectangle.  It then computes and prints the area of the rectangle.

   Tested with:
      Microsoft Visual C++ 6.0
      Microsoft Visual C++ .NET
	  Microsoft Visual Studio 2008
      g++ under Linux
*/

#include <iostream>
using namespace std;


// Function prototypes:

void Explanation(void);

void DoArea(void);


int main(void)
{
    Explanation();
    DoArea();

    return 0;
}


/* Given:  Nothing.
   Task:   To ask the user for the length and width and then to compute
           and print the area.
   Return: Nothing.
*/
void DoArea(void)
{
    float Length, Width, Area;

    cout << "Enter the rectangle's length: ";
    cin >> Length;

    cout << "Enter the rectangle's width: ";
    cin >> Width;

    Area = Length * Width;

    cout << endl << "The area is: " << Area << endl << endl;
}


/* Given:  Nothing.
   Task:   To print an explanation of what the program does.
   Return: Nothing.
*/
void Explanation(void)
{
    cout << "This program computes the area of a rectangle." << endl;
    cout << "You will be prompted to enter both the length and width.";
    cout << endl << "Enter a real number (such as 4 or 2.89) for each.";
    cout << endl << "The program will then compute and print the area.";
    cout << endl << endl;
}

