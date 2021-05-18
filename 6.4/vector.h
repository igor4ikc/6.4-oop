#pragma once
#include <iostream>
#include <math.h>
#include <string>
using namespace std;

template<class T>
class vector
{
	T* v;
	int size;
public:
	vector(int newsize);
	vector(vector&);
	~vector();

	T ext(const char*);
	vector& sort(const char*);
	double norma(void);

	friend vector<T> operator + <>(vector<T>& x, vector<T>& y);
	vector<T>& operator += (vector&);
	T& operator [](int index);
	vector& operator = (const vector&);
	//T find(T const& x, T const& begin, T const& end);

	friend ostream& operator << <>(ostream&, vector&);
	friend istream& operator >> <>(istream&, vector&);
};

template <class T>
vector<T>::vector(int newsize)
{
	v = new T[newsize];
	size = newsize;
	for (int i = 0; i < newsize; i++)
		v[i] = T();
}
template <class T>
vector<T>::vector(vector<T>& x)
{
	v = new T[size = x.size];
	for (int i = 0; i < size; i++)
		v[i] = x.v[i];
}

template <class T>
vector<T>::~vector()
{
	delete[]v;
}

template <class T>
T vector<T>::ext(const char* MinOrMax)
{
	T ExtrElem = v[0];
	for (int i = 0; i < size; i++) {
		if (!strcmp(MinOrMax, "min")) {
			if (v[i] < ExtrElem) ExtrElem = v[i]; // мінімальний елемент 
		}
		else
			if (v[i] > ExtrElem) ExtrElem = v[i]; // максимальний елемент
	}
	return ExtrElem;
}

template <class T>
vector<T>& vector<T>::operator += (vector<T>& y)
{
	for (int i = 0; i < size; i++)
		v[i] += y.v[i];
	return *this;
}

template<class T>
T& vector<T>::operator[](int index)
{
	if (index < 0 || index >= size)
	{
		throw exception("Index out of the range");
	}
	return v[index];

}

template<class T>
vector<T>& vector<T>::sort(const char* UpOrDown)
{
	T x;
	for (int i = 0; i < size - 1; i++)
		for (int j = i + 1; j < size; j++)
			if (!strcmp(UpOrDown, "up"))
			{
				if (v[i] > v[j])
				{
					x = v[i];
					v[i] = v[j];
					v[j] = x;
				}
			}
			else
				if (v[i] < v[j])
				{
					x = v[i];
					v[i] = v[j];
					v[j] = x;
				}
	return *this;
}

template<class T>
double vector<T>::norma(void)
{
	double S = 0;
	for (int i = 0; i < size; i++)
		S += v[i] * v[i];
	return sqrt(S);
}

template <class T>
vector<T> operator + (vector<T>& x, vector<T>& y)
{
	if (x.size != y.size)
	{
		throw exception("The sizes should be the same!");
	}
	vector<T> z(x.size);
	for (int i = 0; i < x.size; i++)
		z.v[i] = x.v[i] + y.v[i];
	return z;
}


template <class T>
vector<T>& vector<T>::operator =(const vector<T>& x)
{
	if (this != &x)
	{
		delete[]v;
		v = new T[size = x.size];
		for (int i = 0; i < size; i++)
			v[i] = x.v[i];
	}
	return *this;
}

template <class T>
istream& operator >> (istream& is, vector<T>& x)
{
	cout << "Input " << x.size << " elements of vector" << endl;
	for (int i = 0; i < x.size; i++) {
		cout << "element[" << i << "] = ? ";
		is >> x.v[i];
	}
	return is;
}
template <class T>
ostream& operator << (ostream& os, vector<T>& x)
{
	for (int i = 0; i < x.size; i++)
		os << x.v[i] << ' ';
	os << endl;
	return os;
}

template <class T>
T* find(T const& x, T* begin, T* end)
{
	T* L = begin, * R = end--, * m;
	while (L <= R)
	{
		m = L + ((int)R - (int)L) / (2 * sizeof(T));
		if (*m == x)
		{
			return m;
		}
		if (*m < x)
		{
			L = m++;
		}
		else
		{
			R = m--;
		}
	}
	return NULL;
}


