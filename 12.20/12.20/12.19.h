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
	StrBlobPtr begin() { return StrBlobPtr(*this); }//�������strblobptr��ʹ�õĵط���ʹ�ù��캯��������strblobptr����
	StrBlobPtr end()
	{
		auto ret = StrBlobPtr(*this, data->size());//this ָ����ָ����øú����Ķ���ĵ�ַ��this�Ǹ�����ָ�롣
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
	StrBlobPtr(StrBlob&a, size_t sz = 0) :wptr(a.data), curr(sz) {}//ʹ����strblob�۵����ݳ�Ա������Ҫ��Ϊ��Ԫ
	string & deref() const;
	StrBlobPtr& incr();
private:
	shared_ptr<vector<string>>check(size_t, const string &msg) const {}
	weak_ptr<vector<string>>wptr;//��һ��ָ��vector<string>����ָ��
	size_t curr;
};

shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string &msg)const
{
	auto ret = wptr.lock();//�ڵ���check������ʱ��strblobptr�Ѿ���ʼ���ˡ���ʱ��wptr�������ݵģ����Լ����ָ����
	if (!ret)
		throw std::runtime_error("unbound StrBlobPtr");
	if (i >= ret->size())
		throw std::out_of_range(msg);
	return ret;//����wptr��ָ����
}

string& StrBlobPtr::deref() const
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];//����wptr��ָ�����curr string
}

StrBlobPtr& StrBlobPtr::incr()
{
	check(curr, "increment past end of strblobptr");
	++curr;//�ȼ��Ŀǰ��curr��û�г��� ��Ȼ�󵥴��Ľ�curr������ݳ�Ա��һ
	return *this;//����curr��һ֮������strblobptr����
}





#endif //STRBLOB