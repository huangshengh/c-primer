#include <algorithm>
#include <list>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	list<string> list1{ "nihao","wohao","dajiahao","nihao" };//��ʼ��ʱҪ�û�����
	auto result = count(list1.begin(), list1.end(), "nihao");
	auto resu = count(list1.begin(), list1.end(), "ni");
	//auto res = find(list1.begin(), list1.end(), "ni");find���û���ҵ���ֵ�Ļ����ǵ���end���������ǲ��ܴ�ӡ������
	cout << result << endl;
	cout << resu << " " << endl;
	system("pause");
	return 0;
}