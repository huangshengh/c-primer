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
	std::multiset<shared_ptr<quote>, decltype(compare)*>items{compare};//�����ؼ�������Ҳ�������ʲô���;����õģ���Ҫ�������ṩ<�������
	//������Ҫ����һ�������͵ıȽϲ������ڹؼ������ͺ��档  
	//decltype(compare)*��˵���multisetҪʹ�ø�compare��Ա������ͬ�ĺ�����������
	//items{compare}�������ڳ�ʼֵ�ķ�ʽ��ʼ��items���󣬲�˵������Ҫ��compare�������Ƚϣ�
	//items(compare)��û�г�ʼ��itemsֻ��˵��������compare�������Ƚϲ���
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
	for (auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter)) //���ص�һ���ؼ��ִ���*iter��Ԫ�صĵ�����,��Ҳ�Ǹ������� 
	{
		sum+=print_total(os,**iter,items.count(*iter));
	}
	os<<"Total Sale:" <<sum<<std::endl;
	return sum;
}




#endif//basket_h
