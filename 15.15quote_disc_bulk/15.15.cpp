#include <iostream>
#include <string>
#include <map>
#include <functional>
#include <vector>
#include <memory>

#include "quote.h"
#include "Disc.h"
#include "Bulk_quote.h"

using std::make_shared;
using std::shared_ptr;
using std::string;
using std::cin;
using std::cout;
using std::vector;
 
double print_total(std::ostream& os, const quote& item, size_t n);

int main()
{
	vector<shared_ptr<quote>> basket;
	basket.push_back(make_shared<Bulk_quote>("0-201-54848-8", 50, 10, 0.25));
	cout << basket.back()->net_price(10) << std::endl;
	//Disc_quote a;
	system("pause");
	return 0;
}

double print_total(std::ostream &os, const quote & item, size_t n)
{
	double ret = item.net_price(n);

	os << "ISBN:" << item.isbn() << "# sold:" << n << "total due:" << ret << std::endl;

	return ret;
} 