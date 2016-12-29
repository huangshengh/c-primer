#ifndef Blob_h
#define Blob_h

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include <algorithm>
#include <utility>
#include <iterator>
#include <initializer_list>
#include <stdexcept>


using std::string;
using std::vector;
using std::shared_ptr;
using std::cout;
using std::cin;
using std::endl;
using std::initializer_list;
using std::make_shared;


template <typename T> class BlobPtr;
template<typename T> class Blob
{
	friend class BlobPtr<T>;
public:
	typedef T value_type;
	typedef typename std::vector<T>::size_type size_type;
	Blob();
	Blob(initializer_list<T> li);
	template<typename V> Blob(V a, V b)
	{
		data = make_shared<vector<T>>(a, b);
	}
	size_type size()  const { return data->size(); }
	bool empty() const { return data->empty(); }
	void push_back(const T&t) { data->push_back(t);}
	void push_back(T &&t) { data->push_back(std::move(t)); }
	void pop_back();
	T& back();
	T& operator[](size_type i);
	T& back() const;
	T& operator[] (size_type i) const;
	T& front();

private:
	shared_ptr<vector<T>> data;
	void check(size_type i, const string&msg)  const;
};


template<typename T>
void Blob<T>::check(size_type i, const string &msg) const
{
	if (i >= data->size())
		throw std::out__of_range(msg);
}

template<typename T>
T& Blob<T>::back()
{
	check(0, "back on empty blob");
	return data->back();
}

template<typename T>
T& Blob<T>::operator[](size_type i)
{
	check(i, "subscript out of range");
	return (*data)[i];
}

template <typename T> void Blob<T>::pop_back()
{
	check(0, "pop_back on empty blob");
	data->pop_back();
}

template<typename T> 
T& Blob<T>::front()
{
	check(O, "size is not enough");
	return data->front();
}

template<typename T>
T& Blob<T>::back() const
{
	check(0, "back on empty blob");
	return data->back();
}

template<typename T>
T& Blob<T>::operator[](size_type i) const
{
	check(i, "subscript out of range");
	return (*data)[i];
}

template <typename T> 
Blob<T>::Blob(): data(make_shared<vector<T>>()){}

template<typename T>
Blob<T>::Blob(initializer_list<T> li):data(make_shared<vector<T>>(li)) {}
#endif // !Blob_h#pragma once
