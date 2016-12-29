#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void ReadFileToVec(const string& fileName, vector<string>& vec)
{
	ifstream ifs(fileName);//���ļ������Ӧ�ļ����ֹ�����
	if (ifs)
	{
		string buf;
		//string str;
		//while (ifs >> str)//���������ո�ʱ��ֹͣ������ʱ�Ͱ�str  push��vec�У�Ȼ��������롣
			//vec.push_back(str);

		while (std::getline(ifs, buf))//ʹ��getline���ļ�����ÿһ�ж�����buf�У�
			vec.push_back(buf);//���ļ�����ÿһ�ж�����stringԪ��push��vector����vec��
	}
}

int main()
{
	vector<string> vec;
	//string a = "test.txt";
	//const string & b = a;
	ReadFileToVec("test.txt", vec);
	for (const auto &str : vec)//���ÿһ��vecԪ��Ҳ�����ļ�����ÿһ��string��
		cout << str << endl;
	system("pause");
	return 0;
}