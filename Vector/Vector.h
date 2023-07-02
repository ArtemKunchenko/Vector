#pragma once
#include <iostream>
#include <initializer_list>
using namespace std;

template<class T>
class Vector
{
public:
	Vector(); //constructor default
	Vector(const Vector& other); // constructor copy
	Vector(Vector&& other); // constructor moving
	Vector& operator= (const Vector& other); // operator copy
	Vector& operator= (Vector&& other); // operator moving
	Vector(initializer_list<T> l);
	~Vector(); // destructor
	friend ostream& operator<<<T> (ostream& out, const Vector& vector);
	void push_back(T item); // add a new item to the end
	void pop_back(); // remove the last element
	int size(); //return size
	void clear();
	T getElement(int index);
	void setElement(T element, int index);
	Vector sort();
	T& operator[] (int index);
private:
	T* _data;
	int _size;
};

