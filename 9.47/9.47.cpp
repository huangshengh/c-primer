#include <iostream>
#include <string>
using namespace std;

int main()
{
	string numbers = ("0123456789"), str = ("ab2c3d7R4E6");
	string alphabet{ "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" };
	for (string::size_type pos = 0; (pos = str.find_first_of(numbers, pos)) != string::npos; ++pos)//����ÿ�����֣��Ǿ�Ҫ�õ�ѭ�����ҵ�һ����ĸ����λ��֮�󣬴����λ��֮���ڽ����ң�ֱ����������
		cout << str[pos] << " ";
	cout << '\n';
	for (string::size_type pos = 0; (pos = str.find_first_of(alphabet, pos)) != string::npos; ++pos)//find_first_of��ָ�����е��ַ���һ����sting�г��ֵ�λ�á�
		cout << str[pos] << " ";
	cout << '\n';
	system("pause");
	return 0;
}