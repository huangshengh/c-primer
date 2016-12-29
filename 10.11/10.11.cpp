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

bool isShorter(const string&s1, const string&s2)
{
	return s1.size() < s2.size();
}

int main()
{
	vector<string> str{ "the","quick","red","fox","jumps","over","the","slow","red","turtle" };
	elimDups(str);
	//stable_sortά�����Ԫ�ص�ԭ��˳��
	stable_sort(str.begin(), str.end(), isShorter);//����ʹ����ν�����������<�����ˣ���isshoter���Ƚ�Ԫ�ض�����֮ǰ��<
	for (const auto&s : str)
		cout << s << " ";
	cout << endl;
	system("pause");
	return 0;
}