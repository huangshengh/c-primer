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
	try {//这个错误检测只检测正则表达式对象,而且这个错误检测能检测出来的只有那么几个
		regex r(pattern);
	}
	catch (std::regex_error e)
	{
		cout << e.what() << "\ncode:" << e.code() << endl;
	}
	//在这里还要在定义一个regex对象。
	regex r(pattern);
  	smatch results;
	string word;
    while (cin >> word)
	  if (regex_search(word, results, r))
			cout << results.str() << endl;

	system("pause");
	return 0;
}