#ifndef basket_h
#define basket_h

#include <iostream>
#include <string>
#include <memory>
#include <set>
#include "quote.h"

using std::cin;
using std::cout;
using std::shared_ptr;
using std::string;

class Basket
{
public:
	friend double print_total(std::ostream& os, const quote& item, size_t n);
	void add_item(const shared_ptr<quote>&sale)
	{
		items.insert(sale);
	}

	void add_item(const quote& sale)
	{
		items.insert(shared_ptr<quote>(sale.clone()));
	}

	void add_item(quote&& sale)
	{
		items.insert(shared_ptr<quote>(std::move(sale).clone()));
	}

	double total_recepit(std::ostream&) const;

private:
	static bool compare(const shared_ptr<quote> &lhs, const shared_ptr<quote> &rhs)
	{ 
		return lhs->isbn() < rhs->isbn();
	}
	std::multiset<shared_ptr<quote>, decltype(compare)*>items{compare};//容器关键字类型也不是随便什么类型就能用的，需要类型能提供<运算符，
	//所以需要定义一个该类型的比较操作跟在关键字类型后面。  
	//decltype(compare)*是说这个multiset要使用跟compare成员类型相同的函数进行排序
	//items{compare}采用类内初始值的方式初始化items对象，并说明我们要用compare函数来比较，
	//items(compare)并没有初始化items只是说明我们用compare函数做比较操作
};


double print_total(std::ostream &os, const quote & item, size_t n)
{
	double ret = item.net_price(n);

	os << "ISBN:" << item.isbn() << "# sold:" << n << "total due:" << ret << std::endl;

	return ret;
}

double Basket::total_recepit(std::ostream& os) const
{
	double sum = 0.0;
	for (auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter)) //返回第一个关键字大于*iter的元素的迭代器,这也是个递增啊 
	{
		sum+=print_total(os,**iter,items.count(*iter));
	}
	os<<"Total Sale:" <<sum<<std::endl;
	return sum;
}




#endif//basket_h
