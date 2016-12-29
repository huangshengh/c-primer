#include <iostream>
#include <string>
using namespace std;

int main()
{
	string numbers = ("0123456789"), str = ("ab2c3d7R4E6");
	string alphabet{ "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" };
	for (string::size_type pos = 0; (pos = str.find_first_of(numbers, pos)) != string::npos; ++pos)//查找每个数字，那就要用到循环。找到一个字母所在位置之后，从这个位置之后在接着找，直到最后结束。
		cout << str[pos] << " ";
	cout << '\n';
	for (string::size_type pos = 0; (pos = str.find_first_of(alphabet, pos)) != string::npos; ++pos)//find_first_of是指参数中的字符第一次在sting中出现的位置。
		cout << str[pos] << " ";
	cout << '\n';
	system("pause");
	return 0;
}