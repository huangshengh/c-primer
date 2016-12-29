#include <iostream>
#include <string>
using namespace std;

struct Sales_data {
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

int main()
{
	Sales_data total;
	if (cin >> total.bookNo >> total.revenue >> total.units_sold)
	{
		Sales_data trans;
		while (cin >> trans.bookNo >> trans.revenue >> trans.units_sold)
		{
			if (total.bookNo == trans.bookNo)
				total.
		}
	}
}