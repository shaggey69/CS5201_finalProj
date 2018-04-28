/*
# myArray class functoins
# By: Ari Sherman
# Class: CS5201 HW #5
# Date: 4.4.18
*/
#include <iostream>
#include <stdexcept>

using namespace std;

//initialize constructor
template <typename T>   
MyArray<T>::MyArray(const int size)
{
	if (size < 0)
		throw std::length_error("size must be greater then zero");
	m_size = size;
	ptr_to_data = new T[m_size];
}

//dedult constructor 
template <typename T>   
MyArray<T>::MyArray()
{
	m_size = 0;
	ptr_to_data = 0;
}

//copy constructor
template <typename T>   
MyArray<T>::MyArray(const MyArray<T>& rhs)
{

	m_size = rhs.m_size;
	ptr_to_data = new T[m_size];
	arrayCopy(rhs);
}

//deconstructor
template <typename T>   
MyArray<T>::~MyArray()
{
	delete [] ptr_to_data;
}

//object getter []
template <typename T>   
T & MyArray<T>::operator[](const int index) const
{
	if (index < 0 || index >= m_size) 
		throw std::out_of_range("index out of range!");
	return ptr_to_data[index];
}

//set size
template <typename T>   
void MyArray<T>::setSize(const int n)
{
	if (n != m_size)
	{
		if (n < 0)
			throw std::length_error("size must be greater then zero");
		delete[] ptr_to_data;
		m_size = n ;
		ptr_to_data = new T[n];
	}
}

//clear
template <typename T>   
void MyArray<T>::clear()
{
	delete[] ptr_to_data;
	m_size = 0;
	ptr_to_data = 0;
}


//= assignment with RHS MyArray
template <typename T>   
MyArray<T>&  MyArray<T>::operator= (const MyArray<T>& rhs)
{
	if (ptr_to_data != rhs.ptr_to_data)
	{
		setSize(rhs.m_size);
		arrayCopy(rhs);
	}
	return (*this);
}

//= assignment with T element
template <typename T>   
MyArray<T>& MyArray<T>::operator= (const T rhs)
{
	T* p =ptr_to_data + m_size;
	while (p  > ptr_to_data)
		*--p= rhs;
	return *this;
}

//= insert
template <typename T>   
void MyArray<T>::insert(const T & x, int pos)
{
	if (pos < 0 || pos >= m_size) 
		throw std::out_of_range("index out of range!");
	ptr_to_data[pos] = x ;
}


//copy function
template <typename T>   
void MyArray<T>::arrayCopy(const MyArray<T> & source)
{

	T* p = ptr_to_data + m_size;
	T* q = source.ptr_to_data + m_size;

	while (p > ptr_to_data)
		*--p = *--q ;
	return;

}

template <typename T>   
bool MyArray<T>::isZeroVec()
{
	for (int i = 0 ; i < m_size ; i++)
		if (ptr_to_data[i] != 0)
			return false;
	return true;
}

template <typename T>   
T MyArray<T>::operator*(const  MyArray<T> & rhs) const
{
	T retVal;
	for (int i = 0; i < rhs.getSize(); i++)
		retVal += ptr_to_data[i]*rhs[i];
	return retVal;
}


template <typename T>   
 MyArray<T> MyArray<T>::operator*(const  T & scaler) const
{
	 MyArray<T> retVal(m_size);
	for (int i = 0; i < m_size; i++)
		retVal[i] = ptr_to_data[i] * scaler;
	return retVal;
}

template <typename T>   
MyArray<T> MyArray<T>::operator+(const  MyArray<T> & rhs) const
{
	MyArray<T> retVal (rhs.getSize());
	for (int i = 0; i < rhs.getSize(); i++)
		retVal[i] = ptr_to_data[i] + rhs.ptr_to_data[i];
	return retVal;
}

template <typename T>   
MyArray<T> MyArray<T>::operator-(const  MyArray<T> & rhs) const
{
	MyArray<T> retVal (rhs.getSize());
	for (int i = 0; i < rhs.getSize(); i++)
		retVal[i] = ptr_to_data[i] - rhs.ptr_to_data[i];
	return retVal;
}



//streamer
template <typename T>   
ostream& operator<< (ostream& out , MyArray<T> & arr)
{
	for (int i = 0; i < arr.getSize() ; i++)
	{	
		out << arr[i] << endl;
	}
	return out;
}
