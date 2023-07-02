#include "Vector.h"
template<class T>
Vector<T>::Vector() : _data(nullptr), _size(0)
{
	cout << "Created vector:\t" << this << endl;
}

template<class T>
Vector<T>::Vector(const Vector& other)
{
	_size = other._size;
	_data = new T[_size];
	for (size_t i = 0; i < _size; i++)
	{
		_data[i] = other._data[i];
	}
	cout << "Constructor copy:\t" << this << endl;
}

template<class T>
Vector<T>::Vector(Vector&& other)
{
	_size = other._size;
	if (other._data != nullptr)
		_data = other._data;
	other._size = 0;
	other._data = nullptr;
	cout << "Constructor moving:\t" << this << endl;
}

template<class T>
Vector<T>& Vector<T>::operator= (const Vector& other)
{
	_size = other._size;
	_data = new T[_size];
	for (size_t i = 0; i < _size; i++)
	{
		_data[i] = other._data[i];
	}
	cout << "Operator copy:\t" << this << endl;
	return *this;
}

template<class T>
Vector<T>& Vector<T>::operator= (Vector&& other)
{
	_size = other._size;
	if (other._data != nullptr)
		_data = other._data;
	other._size = 0;
	other._data = nullptr;
	cout << "Operator moving:\t" << this << endl;
	return *this;
}

template<class T>
Vector<T>::Vector(initializer_list<T> l)
{
	for (const auto& e : l)
		this->push_back(e);
}

template<class T>
Vector<T>::~Vector()
{
	if (_data != nullptr)
		delete[] _data;
	cout << "Destructor:\t" << this << endl;
}

template<class T>
void Vector<T>::push_back(T item)
{
	if (_data != nullptr)
	{
		T* temp = new T[_size];
		for (size_t i = 0; i < _size; i++)
		{
			temp[i] = _data[i];
		}
		delete[] _data;
		_data = new T[++_size]{ 0 };
		for (size_t i = 0; i < _size - 1; i++)
		{
			_data[i] = temp[i];
		}
		delete[] temp;
		_data[_size - 1] = item;
	}
	else
	{
		_data = new T[++_size];
		_data[_size - 1] = item;
	}
}

template<class T>
void Vector<T>::pop_back()
{
	if (_data != nullptr)
	{
		T* temp = new T[--_size];
		for (size_t i = 0; i < _size; i++)
		{
			temp[i] = _data[i];
		}
		delete[] _data;
		if (_size == 0) _data = nullptr;
		_data = new T[_size];
		for (size_t i = 0; i < _size; i++)
		{
			_data[i] = temp[i];
		}
		delete[] temp;
	}
}

template<class T>
int Vector<T>::size()
{
	return _size;
}

template<class T>
void Vector<T>::clear()
{
	if (_data != nullptr)
		delete[] _data;
	_data = nullptr;
	_size = 0;
}

template<class T>
T& Vector<T>::operator[](int index)
{
	return _data[index];
}

template<class T>
ostream& operator<< (ostream& out, const Vector<T>& vector)
{
	for (size_t i = 0; i < vector._size; i++)
	{
		out << vector._data[i] << "  ";
	}
	return out;
}