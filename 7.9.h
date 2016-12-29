#include <string>
#include <vector>
#include <iostream>
using namespace std;


class Person
{
friend istream &read(istream &is, Person &one);//��Ԫ�������������Է��������private����
friend ostream &print(ostream&os,const Person &one);
public:
	//����������ĺ�����Ĭ�ϵ�inline������
	Person() = default;//Ĭ�ϵĹ��캯�����õ���ĳ�ʼֵ��ʼ��
	Person(const string &s,const string &st):name(s),address(st){}//���캯����
	vector<string> info() const
	{
		vector<string> list;
		list.push_back(name);
		list.push_back(address);
		return list;
	}//�������ֺ͵�ַ�ĳ�Ա������
private:
	string name = "admin";
	string address= "no";
};

//person�ķǳ�Ա�ӿں���
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