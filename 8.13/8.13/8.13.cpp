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
		while (!isdigit(c))//�����һ������������ôa���Ǽ٣��᷵�ؼ�
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
	ifstream ifs("test.txt");//���ļ������������ļ�,��ҪadminȨ��
	while (ifs)//���ļ������ɹ�
	{
		while (getline(ifs, line))//���ļ���ÿһ�ж��뵽line��
		{
			PersonInfo info;
			record.clear();
			record.str(line);//��Ϊifstream������ѭ��֮������Ҫ��str����������string����
			record >> info.name;//�Ȱ�nameֵ��info.name
			while (record >> word)//ʣ�µĸ�wordʣ�¾��ǵ绰����
				info.phones.push_back(word);
			people.push_back(info);
		}
	}

	for (const auto& entry : people)
	{
		ostringstream formatted, badNums;
		for (const auto & nums : entry.phones)
		{
			if (!valid(nums))//����������ؼ٣���ô��˵�����������⡣
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