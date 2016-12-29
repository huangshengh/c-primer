#include <iostream>
#include "Sales_item.h"
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
	istream_iterator<Sales_item> in(cin), eof;
	vector<Sales_item>vec;

	Sales_item total;
	if (cin >> total)
	{
		Sales_item trans;
		while (cin >> trans)
		{
			if (total.isbn() == trans.isbn())
				total += trans;
			else
			{
				cout << total << endl;
				total = trans;
			}
	    }
		cout << total << endl;
	}
	else
	{
		cout << "No data?!" << endl;
		return -1;
	}
	system("pause");
	return 0;
}