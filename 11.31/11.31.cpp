#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int main()
{
	multimap<string, string>author;
	string name,item;
	author.insert({ "huang","yi" });//����Ԫ��ʱҪ��{}
	author.emplace( "huang","er" );//empalceҲ����ʹ������Ԫ�����pair.
	author.insert({ "huang","san" });
	author.insert({ "wang","yi" });
	for (auto c : author)
		cout << c.first << " " << c.second << endl;
	cout << "which author you want to delete?" << endl;
	while (cin >> name)
		item = name;
	auto a = author.find(item);
	if (a!=author.end())
	author.erase(item);
    else
		cout << "does not exit" << endl;
    for (auto e : author)
		cout << e.first << " " << e.second << endl;
	system("pause");
	return 0;
}