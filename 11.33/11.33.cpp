#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>// 定义异常类的头文件

using namespace std;

//建立转换映射
map<string, string>build_map(ifstream & map_file)//参数是一个ifstream的类型引用，读取文件流。那么map_file就需要绑定到规则文件上
{
	map<string, string>trans_map;
	string key;
	string value;
	while (map_file >> key && getline(map_file, value))//mapfile第一个单词存入了key，行中剩下内容放进value
		//getline读取剩下的行之后，会返回流参数，所以map_file是新的一行的开始
	{
		if (value.size() > 1)//说明value中有key到value的那个空格
			trans_map[key] = value.substr(1);//把那个空格去掉，拷贝从对应值开始的string   
		else
			throw runtime_error("no rule fo " + key);//只有在运行时才能检测出问题。
	}
	return trans_map;
}


//生成转换文本
const string & transform(const string &s, const map<string, string>&m)//每个要输出的string单词 都要经过这一过程 s和m匹配一下
{
	auto map_it = m.find(s);
	if (map_it != m.cend())//若s在转换规则里就返回对应的文本，否则
		return map_it->second;
	else
		return s;
}

//转换程序
void word_transform(ifstream & map_file, ifstream & input)//函数使用引用参数可以改变实参的值，当实参拷贝给形参时，函数不会改变
//实参的值，但有的时候，实参不能拷贝，如io类型不能被拷贝或拷贝效率低
{
	auto trans_map = build_map(map_file);
	string text;
	while (getline(input, text))
	{
		istringstream stream(text);//将text与string输入流类型的对象绑定，从text读取对象；
		string word;
		bool firstword = true;
		while (stream >> word)
		{
			if (firstword)
				firstword = false;
			else
				cout << " ";//每一行都读入text中，再从text中读取每一个单词，如果是第一个单词就不用空格，后面的单词需要空格；
			cout << transform(word, trans_map);//打印输出
		}
		cout << endl;//getline是见到换行符停止，但是还行并不会拷贝到sting对象中，所以每一行的操作结束后，需要换行
	}
}

int main()
{
	string word;
	wchar_t const name[] = L"D:\\rules.txt";
	wchar_t const call[] = L"D:\\trans.txt";
	try 
	{
		ifstream map_file;
		map_file.open(name);
		map_file >> word;
		cout << word << endl;
		ifstream input;
		input.open(call);
		word_transform(map_file, input);
	}
	catch (runtime_error) 
	{
		cout << "did not open file" << endl;
	}
	system("pause");
	return 0;
}