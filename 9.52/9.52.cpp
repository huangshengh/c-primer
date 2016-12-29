#include <stack>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	string expression{ "this is (pezy)." };
	bool bseen = false;
	stack<char> stk;//适配器
	for (const auto&s : expression)
	{
		if (s == '(')
		{
			bseen = true;
			continue;
		}
		if (bseen)
			stk.push(s);
	}
	string repstr;
	while (!stk.empty())
	{
		repstr += stk.top();
		stk.pop();
	}
	expression.replace(expression.find("(") + 1, repstr.size(), repstr);//replace(range,str),range可以是一个下标和一个长度，也可以是指向s的迭代器。
	cout << expression << endl;
	system("pause");
	return 0;
}