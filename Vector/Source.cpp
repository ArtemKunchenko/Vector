#include <iostream>
#include <string>
#include "Vector.h"
#include "Vector.cpp"
using namespace std;
template<class T>
static Vector<T> sort(Vector <T> vector)
{
	T temp;
	for (int i = 0; i < vector.size() - 1; i++)
	{
		for (int j = i + 1; j < vector.size(); j++)
		{
			if (vector.getElement(j) < vector.getElement(i))
			{
				temp = vector.getElement(j);
				vector.setElement(vector.getElement(i), j);
				vector.setElement(temp, i);
			}
		}
	}
	return vector;
}
int main()
{
	Vector<int> v{ 15, 1, 8, 6, 9, 15, 5, 5 };
	Vector<int> v2{ 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	cout << v << endl;
	cout << v.sort() << endl;
	Vector<int> v3 = sort(v2);
	cout << v2 << endl;
	cout << v3 << endl;
	system("pause");
	return 0;
}