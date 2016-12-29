#include <string>
#include <vector>
#include <iostream>
using namespace std;


class Person
{
friend istream &read(istream &is, Person &one);//友元函数，这样可以访问类里的private对象
friend ostream &print(ostream&os,const Person &one);
public:
	//定义在类里的函数是默认的inline函数；
	Person() = default;//默认的构造函数，用的类的初始值初始化
	Person(const string &s,const string &st):name(s),address(st){}//构造函数；
	vector<string> info() const
	{
		vector<string> list;
		list.push_back(name);
		list.push_back(address);
		return list;
	}//返回名字和地址的成员函数；
private:
	string name = "admin";
	string address= "no";
};

//person的非成员接口函数
istream &read(istream &is, Person &one)
{
	is >> one.name >> one.address;
	return is;
}

ostream &print(ostream&os, const Person &one)
{
	os << one.name << ' ' << one.address;
	return os;
}