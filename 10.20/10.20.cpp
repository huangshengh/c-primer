#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
using namespace std;

void elimDups(vector<string> &words)
{
	sort(words.begin(), words.end());//�Ƚ�words���ֵ�������
	//�ڽ�words���ظ��ķ��ں��棬���ص��ǲ��ظ����ֺ�һ��λ�õĵ�����
	auto end_unique = unique(words.begin(), words.end());
	//ɾ��������words�о�û����ͬ��stringԪ����
	words.erase(end_unique, words.end());
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
	elimDups(words);
	//ʹ��stable_sort�ó�����ͬ��Ԫ�ذ���ԭ�������򣬳���Ԫ�����ں��浫�Ƕ���ѭ�ֵ���
	stable_sort(words.begin(), words.end(), [](const string &a, const string &b) {return a.size() < b.size(); });
	//�����ж����ν�ʳ���
	auto count = count_if(words.begin(), words.end(), [sz](const string &a) {return a.size() > sz; });
	cout << count << endl;
}


int main()
{
	vector<string> str{ "wodemaya","zenmexue","xiaqua" };
	biggies(str, 6);
	system("pause");
	return 0;
}
