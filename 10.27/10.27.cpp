#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
	vector<string> str{ "nihao","nihao","nihao","wohao","nixianzai","nihao" };
	list<string>list1;
	//����Ҫ�����ǣ�һuniqueֻ�������ڵ��ظ�������copy����Ҫ�ı�list�ģ�������Ҫ�õ������������
	unique_copy(str.begin(), str.end(),back_inserter(list1));
	for_each(list1.begin(), list1.end(), [](const string &s) {cout << s << " "; });
	cout << endl;
	system("pause");
	return 0;
}