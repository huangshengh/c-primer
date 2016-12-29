#include <algorithm>
#include <list>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	list<string> list1{ "nihao","wohao","dajiahao","nihao" };//初始化时要用花括号
	auto result = count(list1.begin(), list1.end(), "nihao");
	auto resu = count(list1.begin(), list1.end(), "ni");
	//auto res = find(list1.begin(), list1.end(), "ni");find如果没有找到该值的话，是等于end（），但是不能打印出来。
	cout << result << endl;
	cout << resu << " " << endl;
	system("pause");
	return 0;
}