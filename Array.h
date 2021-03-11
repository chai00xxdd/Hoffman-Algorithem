#pragma once
#include<iostream>
#include<exception>
template<class T>
class Array
{
private:
	T**arr=nullptr;//more efficent on swaps
	int log=0;
	int phy=0;
public:
	//ctors dtors
	Array(int size = 0);
	Array(Array&&other);
	Array(const Array&other);
	~Array();
	//return the last element in the array
	T&last();
	const T&last()const;
	//inserting item to the end of the array
	void push_back(const T&item);
	//return the log size of the array
	int length()const { return log; }
	//return the physical size of the array
	int capacity()const { return phy; }
	//clear all the elements and fress the array
	void clear();
	//resize the size of the array to size
	void resize(int size);
	//operators
	const Array& operator=(const Array&other);
	T&operator[](int index);
	const T&operator[](int index)const;
	


};
template<class T>
Array<T>::Array(const Array<T>&other)
{
	
	*this = other;
}
template<class T>
Array<T>::Array(int size )
{
	if (size > 0)
	{
		log = size;
		phy = log * 2;
		arr = new T*[phy]();
	}
}
template<class T>
Array<T>::~Array()
{
	clear();

}
template <class T>
void Array<T>::clear()
{
	for (int i = 0; i < log; i++)
		delete arr[i];
	delete arr;
	arr = nullptr;
	log = phy = 0;
}
template<class T>
const Array<T>& Array<T>::operator=(const Array<T>&other)
{
	clear();
	log = other.log;
	phy = other.phy;
	if (phy)
	{
		arr = new T*[phy]();
		for (int i = 0; i < log; i++)
		{
			if (other.arr[i] == nullptr)
				arr[i] = nullptr;
			else arr[i] = new T(other[i]);
		}
	}
	return *this;
}
template<class T>
void Array<T>::push_back(const T&item)
{
	if (phy == 0)
	{
		phy = 1;
		arr = new T*[phy];
	}
	else if (log == phy)
	{
		phy *= 2;
		T**resized = new T*[phy]();
		for (int i = 0; i < log; i++)
			resized[i] = arr[i];
		delete arr;
		arr = resized;
	}
	arr[log++] = new T(item);
}
template <class T>
T& Array<T>::operator[](int index)
{
	const Array&thisConst = *this;
	return const_cast<T&>(thisConst[index]);
}
template<class T>
const T& Array<T>::operator[](int index)const
{
	if (index<0 || index>=log)
		throw std::exception("out of bound");
	else if (arr[index] == nullptr)
		arr[index] = new T();
	return *arr[index];
}

template<class T>
void Array<T>::resize(int size)
{
	
	if (size == 0)
	{
		clear();
		return;
	}
	T**resized = new T*[size]();
	int minimum = size < log ? size : log;
	for (int i = 0; i < minimum; i++)
		resized[i] = arr[i];
	for (int i = minimum ; i < log; i++)
		delete arr[i];
	delete arr;
	arr = resized;
	log = phy = size;
	
}


template<class T>
Array<T>::Array(Array&&other)
	:arr(other.arr),log(other.log),phy(other.log)
{
	other.arr = nullptr;
	other.log = other.phy = 0;
}

template<class T>
T& Array<T>::last()
{
	if (log == 0)
		throw std::exception("array is empty!!!");
	return (*this)[log - 1];
}
template<class T>
const T& Array<T>::last()const
{
	if (log == 0)
		throw std::exception("array is empty!!!");
	return (*this)[log - 1];
}
