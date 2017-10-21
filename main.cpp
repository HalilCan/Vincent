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

    struct PartType
    {
        int PartNumber;
        float Price;
    };
    PartType part01;
    part01.PartNumber = 10;
    cout << part01.PartNumber << endl;

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


/* Given:   Value      a floating point number
            NumPlaces  a positive integer giving the number of
                       decimal places to which to round the answer.
   Task:    To round Value to NumPlaces decimal places.  If NumPlaces
            is not postive, Value is returned unchanged as the answer.
   Return:  The rounded number in the function name.
*/
float Round4(float Value, int NumPlaces)
{
    int k, Temp;
    float Factor;

    Factor = 1;
    for (k = 0; k < NumPlaces; k++)
        Factor = Factor * 10;

    Temp = Value * Factor + 0.5;
    return Temp / Factor;
}