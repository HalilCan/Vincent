#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void DoArea(void);

int main() {
    int num, answer, temp, value;
    num = 45;
    answer = num + 1;
    temp = num;
    value = 2 * num + answer;

    int Value = 85;
    int Total = 144;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << "Hello, Hal!" << endl;
    std::cout << "Hello, World!" << std::endl;

    cout << "The square root of 1.44 is: " << sqrt(1.44) << endl;

    DoArea();



    cout << setw(8) << "Value" << setw(8) << "Total" << endl;
    cout << setw(8) << Value << setw(8) << Total << endl;

    return 0;
}

/* Given:  Void
   Task:   Determine the area of a predetermined floating-point rectangle
   Return: Void (cout the result)
*/
void DoArea() {
    float length, width;
    length = 10.3088f;
    width = 5.219f;
    cout << "The Area of a rectangle with dimensions 5.2 and 10.3 is: " << width*length << endl;
}

/* Given:  Value  a floating point number
   Task:   To round Value to 2 decimal places.
   Return: The rounded number in the function name.
*/
float Round2(float Value)
{
    int Temp;

    Temp = Value * 100.0 + 0.5;
    return Temp / 100.0;
}