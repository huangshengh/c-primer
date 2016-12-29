#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

struct PersonInfo {
	string name;
	vector<string> phones;
};

bool valid(const string str)
{
	bool a = true;
	for (auto c : str)
		while (!isdigit(c))//如果有一个不是数字那么a就是假，会返回假
			a = false;
	return a;
}

string format(const string str)
{
	string a = str;
	return a;
}

int main()
{
	string line, word;
	vector<PersonInfo> people;
	istringstream record;
	ifstream ifs("test.txt");//用文件输入来关联文件,需要admin权限
	while (ifs)//当文件关联成功
	{
		while (getline(ifs, line))//从文件的每一行读入到line中
		{
			PersonInfo info;
			record.clear();
			record.str(line);//因为ifstream生命在循环之外所以要用str（）来关联string对象
			record >> info.name;//先把name值给info.name
			while (record >> word)//剩下的给word剩下就是电话号码
				info.phones.push_back(word);
			people.push_back(info);
		}
	}

	for (const auto& entry : people)
	{
		ostringstream formatted, badNums;
		for (const auto & nums : entry.phones)
		{
			if (!valid(nums))//如果函数返回假，那么就说明数字有问题。
			{
				badNums << " " << nums;
			}
			else
				formatted << " " << format(nums);
		}
		if (badNums.str().empty())
			cout << entry.name << " " << formatted.str() << endl;
		else
			cerr << "input error!: " << entry.name << "invalid number(s) " << badNums.str() << endl;
	}
	system("pause");
	return 0;
}