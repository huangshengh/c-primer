#include <regex>
#include <string>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::smatch;
using std::cmatch;
using std::regex_search;
using std::regex;

int main()
{
	string pattern("el");
	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
	try {//���������ֻ���������ʽ����,��������������ܼ�������ֻ����ô����
		regex r(pattern);
	}
	catch (std::regex_error e)
	{
		cout << e.what() << "\ncode:" << e.code() << endl;
	}
	//�����ﻹҪ�ڶ���һ��regex����
	regex r(pattern);
  	smatch results;
	string word;
    while (cin >> word)
	  if (regex_search(word, results, r))
			cout << results.str() << endl;

	system("pause");
	return 0;
}