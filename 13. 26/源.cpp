#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>
#include <stdexcept>

using std::vector;
using std::string;
using std::shared_ptr;
using std::make_shared;
using std::initializer_list;

class StrBlob
{
public:
	typedef vector<string>::size_type size_type;
	StrBlob() :data(make_shared<vector<string>>()) {}
	StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}
	StrBlob(const StrBlob& rh):data(make_shared<vector<string>>(*rh.data)){}
	StrBlob& operator = (const StrBlob& rh)
	{
		auto newp = make_shared<vector<string>>(*rh.data);
		data = newp;
		return *this;
	}
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