#ifndef Blobptr_h
#define Blobptr_h

#include "blob.h"

using std::weak_ptr;

template<typename T>
class BlobPtr
{
public:
	BlobPtr():curr(0){}
	BlobPtr(Blob<T>a, size_t sz = 0):wptr(a.data),curr(sz){}
	T& operator*() const
	{
		auto p = check(curr, "deference past end");
		return (*p)[curr];
	}//(*p)是vector
	//前置递增，递减运算符
	BlobPtr& operator++();
	BlobPtr& operator--(); 

	//postoperator
	BlobPtr operator--(int);
private:
	shared_ptr<vector<T>> check(const size_t, const string&) const;
	size_t curr;
	weak_ptr<vector<T>> wptr;

};

#endif // !Blobptr_h#pragma once

template<typename T>
shared_ptr<vector<T>> BlobPtr<T>::check(const size_t i,const string&s) const
{
	if (i >= data->size())
		throw std::out_of_range(s);
}

template<typename T>
BlobPtr<T>& BlobPtr<T>::operator++()
{
	check(curr, "can't plus");
	++curr;
	return *this;
}

template<typename T>
BlobPtr<T>& BlobPtr<T>::operator--()
{
	check(curr, "can't");
	--curr;
	return *this;
}

//后置的递增运算符
template<typename T>
BlobPtr<T> BlobPtr<T>::operator ++(int)
{
	BlobPtr ret = *this;
	++*this;
	return ret;
}

template<typename T>
BlobPtr<T> BlobPtr<T>::operator --(int)
{
	BlobPtr ret = *this;
	--*this;
	return ret;
}


 