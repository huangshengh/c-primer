#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <functional>
using namespace std::placeholders;
using namespace std;

//��������ȷ������Ҫ�ĺ����������������Ҫ�����������ǿ��Եģ����������ڲ�ͬ�ķ����㷨��ʹ��
bool check_size(const string &s, string::size_type sz)
{
	return s.size() > sz;
}



void elimDups(vector<string> &words)
{
	sort(words.begin(), words.end());//�Ƚ�words���ֵ�������
									 //�ڽ�words���ظ��ķ��ں��棬���ص��ǲ��ظ����ֺ�һ��λ�õĵ�����
	auto end_unique = unique(words.begin(), words.end());
	//ɾ��������words�о�û����ͬ��stringԪ����
	words.erase(end_unique, words.end());
}

void biggies(vector<string> &words)
{
	elimDups(words);
	//ʹ��stable_sort�ó�����ͬ��Ԫ�ذ���ԭ�������򣬳���Ԫ�����ں��浫�Ƕ���ѭ�ֵ���
	stable_sort(words.begin(), words.end(), [](const string &a, const string &b) {return a.size() < b.size(); });
	//�����ж����ν�ʳ��棬ʹ��bind�����ã��������������㷨����Ҫ��
	auto count = count_if(words.begin(), words.end(), bind(check_size, _1, 6) );
	cout << count << endl;
}


int main()
{
	vector<string> str{ "wodemaya","zenmexue","xiaqua" };
	biggies(str);
	system("pause");
	return 0;
}
