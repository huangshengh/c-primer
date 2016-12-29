#ifndef CP5_CH14_EX02_H
#define CP5_CH14_EX02_H

#include <string>
#include <iostream>

using std::string;
using std::istream;
using std::ostream;


class isbn_mismatch : public std::logic_error
{
public :
	explicit isbn_mismatch(const string &s):std::logic_error(s){}
	isbn_mismatch(const string&s, const string&lhs, const string&rhs):std::logic_error(s),left(lhs),right(rhs){}
	const string left, right;

};

class Sales_data
{
	friend std::hash<Sales_data>;
	friend std::istream& operator>>(std::istream&, Sales_data&);
	friend ostream& operator<<(ostream&, const Sales_data&);
	friend Sales_data operator+(const Sales_data&, const Sales_data&);
public:
	Sales_data(const string &s,unsigned n,double p ):bookNo(s),units_sold(n),revenue(n*p){}
	Sales_data():Sales_data(" ",0,0.0f){}
	Sales_data(const string &s):Sales_data(s,0,0.0f){}
	Sales_data(std::istream &is);

	Sales_data& operator=(const string&);
	Sales_data& operator+=(const Sales_data&);
	string isbn() const { return bookNo; }
private:
	inline double avg_price() const;

	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

std::istream& operator>>(std::istream&, Sales_data&);
ostream& operator<<(ostream&, const Sales_data&);
Sales_data operator+(const Sales_data&, const Sales_data&);

inline double Sales_data::avg_price() const
{
	return units_sold ? revenue / units_sold : 0;
}

#endif // !CP5_CH14_EX02_H#pragma once
