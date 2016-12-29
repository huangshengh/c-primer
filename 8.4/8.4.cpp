#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void ReadFileToVec(const string& fileName, vector<string>& vec)
{
	ifstream ifs(fileName);//打开文件流与对应文件保持关联；
	if (ifs)
	{
		string buf;
		//string str;
		//while (ifs >> str)//当它遇见空格时会停止输入这时就把str  push进vec中，然后接着输入。
			//vec.push_back(str);

		while (std::getline(ifs, buf))//使用getline将文件流中每一行都读入buf中；
			vec.push_back(buf);//将文件流中每一行都当成string元素push到vector类型vec中
	}
}

int main()
{
	vector<string> vec;
	//string a = "test.txt";
	//const string & b = a;
	ReadFileToVec("test.txt", vec);
	for (const auto &str : vec)//输出每一个vec元素也就是文件流中每一行string；
		cout << str << endl;
	system("pause");
	return 0;
}