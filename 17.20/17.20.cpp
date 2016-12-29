#include <iostream>
#include <string>
#include <regex>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::regex;
using std::smatch;
using std::sregex_iterator;
using std::regex_replace;
using std::regex_constants::format_no_copy;

bool valid(const smatch &m)
{
	if (m[1].matched)
		return m[3].matched && (m[4].matched == 0 || m[4].str() == " ");
	else
		return !m[3].matched&&m[4].str() == m[6].str();
}


int main()
{
	string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
	try 
	{
		regex r(phone);
	}
	catch (std::regex_error e)
	{
		cout << e.what() << "\ncode:" << e.code() << endl;
	}

	regex r(phone);
	smatch results;
	string numbers;
	string fmt = "$2.$5.$7";
	while (getline(cin,numbers))
	{
		for (sregex_iterator it(numbers.begin(), numbers.end(), r), end_it; it != end_it; ++it)
		{
			if (valid(*it))
				cout << "valid:" << it->str() << endl;
			else
				cout << "not valid: " << it->str() << endl;

		}
		cout << regex_replace(numbers, r, fmt) << endl;//这个会把输入序列全部打印出来，修改fmt对应的部分
		cout << regex_replace(numbers, r, fmt,format_no_copy) << endl;//只打印修改部分。
	}
	/*string a;
	while (cin >> a)
		cout << a << endl;*/

	

	system("pause");
	return 0;
}