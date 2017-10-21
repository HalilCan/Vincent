#include <iostream>
#include <cmath>
using namespace std;

void DoArea(void);

int main() {
    int num, answer, temp, value;
    num = 45;
    answer = num + 1;
    temp = num;
    value = 2 * num + answer;

    cout << "Hello, Hal!" << endl;
    std::cout << "Hello, World!" << std::endl;

    cout << "The square root of 1.44 is: " << sqrt(1.44) << endl;

    DoArea();

    return 0;
}

void DoArea() {
    float length, width;
    length = 10.3f;
    width = 5.2f;
    cout << "The Area of a rectangle with dimensions 5.2 and 10.3 is: " << width*length << endl;
}
