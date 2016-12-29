#ifndef STRBLOB
#define STRBLOB

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>
#include <stdexcept>
#include <exception>

using std::vector;
using std::string;
using std::shared_ptr;
using std::make_shared;
using std::initializer_list;
using std::weak_ptr;
using std::size_t;


class StrBlobPtr;
class ConstStrBlobPtr;

class StrBlob
{
	//using size_type = vector<string>::size_type;
	friend class ConstStrBlobPtr;
	friend class StrBlobPtr;
	friend bool operator ==(const StrBlob&, const StrBlob&);
	friend bool operator !=(const StrBlob&, const StrBlob&);
	friend bool operator <(const StrBlob&, const StrBlob&);
	friend bool operator >(const StrBlob&, const StrBlob&);
	friend bool operator <=(const StrBlob&, const StrBlob&);
	friend bool operator >=(const StrBlob&, const StrBlob&);
	
public:
	typedef vector<string>::size_type size_type;
	StrBlob() :data(make_shared<vector<string>>()) {}
	StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	void push_back(const string &t) { data->push_back(t); }
	void pop_back();
	string & front() const;
	string & back() const;
	string & front();
	string & back();

private:
	shared_ptr<vector<string>> data;
	void check(size_type i, const string & msg) const;
	StrBlobPtr begin() { return StrBlobPtr(*this); }//这个就是strblobptr类使用的地方，使用构造函数来构造strblobptr对象
	StrBlobPtr end()
	{
		auto ret = StrBlobPtr(*this, data->size());//this 指针是指向调用该函数的对象的地址。this是个常量指针。
		return ret;
	}
};

void StrBlob::check(size_type i, const string &msg) const
{
	if (i >= data->size())
		throw std::out_of_range(msg);
}

string & StrBlob::front()
{
	check(0, "front on empty StrBlob");
	return data->front();
}

string& StrBlob::back()
{
	check(0, "back on empty StrBlob");
	return data->back();
}

string&  StrBlob::front() const
{
	check(0, "front on empty strblob");
	return data->front();
}

string& StrBlob::back() const
{
	check(0, "back on empty strblon");
	return data->back();
}

void StrBlob::pop_back()
{
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}


class StrBlobPtr
{
public:
	StrBlobPtr() :curr(0) {}
	StrBlobPtr(StrBlob&a, size_t sz = 0) :wptr(a.data), curr(sz) {}//使用了strblob累的数据成员，所以要成为友元
	string & deref() const;
	StrBlobPtr& incr();
private:
	shared_ptr<vector<string>>check(size_t, const string &msg) const {}
	weak_ptr<vector<string>>wptr;//是一个指向vector<string>的弱指针
	size_t curr;
};

shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string &msg)const
{
	auto ret = wptr.lock();//在调用check函数的时候，strblobptr已经初始化了。此时的wptr是有内容的，可以检查所指对象
	if (!ret)
		throw std::runtime_error("unbound StrBlobPtr");
	if (i >= ret->size())
		throw std::out_of_range(msg);
	return ret;//返回wptr所指对象
}

string& StrBlobPtr::deref() const
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];//返回wptr所指对象的curr string
}

StrBlobPtr& StrBlobPtr::incr()
{
	check(curr, "increment past end of strblobptr");
	++curr;//先检查目前的curr有没有出界 ，然后单纯的将curr这个数据成员加一
	return *this;//返回curr加一之后的这个strblobptr对象
}





#endif //STRBLOB