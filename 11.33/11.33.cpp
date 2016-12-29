#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>// �����쳣���ͷ�ļ�

using namespace std;

//����ת��ӳ��
map<string, string>build_map(ifstream & map_file)//������һ��ifstream���������ã���ȡ�ļ�������ômap_file����Ҫ�󶨵������ļ���
{
	map<string, string>trans_map;
	string key;
	string value;
	while (map_file >> key && getline(map_file, value))//mapfile��һ�����ʴ�����key������ʣ�����ݷŽ�value
		//getline��ȡʣ�µ���֮�󣬻᷵��������������map_file���µ�һ�еĿ�ʼ
	{
		if (value.size() > 1)//˵��value����key��value���Ǹ��ո�
			trans_map[key] = value.substr(1);//���Ǹ��ո�ȥ���������Ӷ�Ӧֵ��ʼ��string   
		else
			throw runtime_error("no rule fo " + key);//ֻ��������ʱ���ܼ������⡣
	}
	return trans_map;
}


//����ת���ı�
const string & transform(const string &s, const map<string, string>&m)//ÿ��Ҫ�����string���� ��Ҫ������һ���� s��mƥ��һ��
{
	auto map_it = m.find(s);
	if (map_it != m.cend())//��s��ת��������ͷ��ض�Ӧ���ı�������
		return map_it->second;
	else
		return s;
}

//ת������
void word_transform(ifstream & map_file, ifstream & input)//����ʹ�����ò������Ըı�ʵ�ε�ֵ����ʵ�ο������β�ʱ����������ı�
//ʵ�ε�ֵ�����е�ʱ��ʵ�β��ܿ�������io���Ͳ��ܱ������򿽱�Ч�ʵ�
{
	auto trans_map = build_map(map_file);
	string text;
	while (getline(input, text))
	{
		istringstream stream(text);//��text��string���������͵Ķ���󶨣���text��ȡ����
		string word;
		bool firstword = true;
		while (stream >> word)
		{
			if (firstword)
				firstword = false;
			else
				cout << " ";//ÿһ�ж�����text�У��ٴ�text�ж�ȡÿһ�����ʣ�����ǵ�һ�����ʾͲ��ÿո񣬺���ĵ�����Ҫ�ո�
			cout << transform(word, trans_map);//��ӡ���
		}
		cout << endl;//getline�Ǽ������з�ֹͣ�����ǻ��в����´����sting�����У�����ÿһ�еĲ�����������Ҫ����
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