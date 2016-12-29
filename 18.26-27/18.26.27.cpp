#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::string;

struct Base1
{
	void print(int) const;
protected:
	int ival;
	double dval;
	char cval;
private:
	int *id;
};

struct Base2
{
	void print(double) const;
protected:
	double fval;
private:
	double dval;
};

struct Derived :public Base1
{
	void print(string) const;
protected:
	string sval;
	double dval;
};

struct MI :public Derived, public Base2
{
	void print(vector<double>);
protected:
	int *val;
	vector<double> dvec;
};

int main()
{
	MI mi;
	mi.Base1::print(42);
	system("pause");
	return 0;
}