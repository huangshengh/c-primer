#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
using namespace std;


void elimDups(vector<string> &words)
{
	sort(words.begin(), words.end());//ʹ��sort����֮���words��������֮��ġ�
	for (auto c : words)
		cout << c << " ";
	cout << endl;
	auto end_unique = unique(words.begin(), words.end());//end_uniuqe�ķ����������ظ�֮��ģ����ظ����ֵĺ�һ��λ�õĵ�������
	for (auto c : words)
		cout << c << " ";
	cout << endl;
	words.erase(end_unique, words.end());//���ظ�����ɾ����
	for (auto c : words)
		cout << c << " ";
	cout << endl;
}

int main()
{
	vector<string> book{ "you","should","learn","how","to","forget","it","to","be","better" };
	elimDups(book);
	system("pause");
	return 0;
}