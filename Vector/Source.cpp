#include <iostream>
#include <string>
#include "Vector.h"
#include "Vector.cpp"
using namespace std;

int main()
{
    Vector<int> v{ 15, 1, 8, 6, 9, 15, 5, 5};
    cout << v << endl;
    system("pause");
    return 0;
}