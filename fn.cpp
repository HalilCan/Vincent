/* Filename:  fn.cpp

   Author:  Br. David Carlson

   Date:  May 12, 1998

   Revised:  July 20, 2000; November 21, 2001

   This program finds the area and perimeter of two rectangles.  The length
   and width of the rectangles are hard-coded.  The area and perimeter
   results are printed on the screen.

   Tested with:
      Microsoft Visual C++ 6.0
      Microsoft Visual C++ .NET
      g++ under Linux
*/

#include <iostream>
using namespace std;


// Function prototypes:

void FindArea(float Length, float Width, float & Area);

float FindPerimeter(float Length, float Width);


int main(void)
{
    float Length, Width, Area, Perim;

    Length = 3.4;
    Width = 1.2;

    // Typical ways to call the two functions:
    FindArea(Length, Width, Area);
    Perim = FindPerimeter(Length, Width);

    cout << "For the rectangle with length " << Length <<
         " and width " << Width << endl;
    cout << "   the area is " << Area << endl;
    cout << "   and the perimeter is " << Perim << endl << endl;

    FindArea(5.67, 2.5, Area);
    cout << "For the rectangle with length 5.67 and width 2.5" << endl;
    cout << "   the area is " << Area << endl;
    // This function call is embedded in an output statement:
    cout << "   and the perimeter is " << FindPerimeter(5.67, 2.5)
         << endl << endl;

    return 0;
}


/* Given:  Length   The length of a rectangle.
           Width    The width of a rectangle.
   Task:   To calculate the area of this rectangle.
   Return: Area     The area of this rectangle.
*/
void FindArea(float Length, float Width, float & Area)
{
    Area = Length * Width;
}


/* Given:  Length   The length of a rectangle.
           Width    The width of a rectangle.
   Task:   To calculate the perimeter of this rectangle.
   Return: This perimeter in the function name.
*/
float FindPerimeter(float Length, float Width)
{
    return 2 * (Length + Width);
}

