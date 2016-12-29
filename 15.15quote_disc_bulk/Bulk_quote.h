#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H

#include"Disc.h"

class Bulk_quote :public Disc_quote
{
public:
	Bulk_quote() = default;
	using Disc_quote::Disc_quote;//只继承了一个构造函数。
	//Bulk_quote(const string &book,double price,size_t qty,double disc):Disc_quote(b,p,q,d){}在编译器中生成这样 
	Bulk_quote(const string& b,double p, std::size_t q,double disc):
		Disc_quote(b,p,q,disc){}

	Bulk_quote(const Bulk_quote&rhs):Disc_quote(rhs){}
	Bulk_quote(Bulk_quote&&rhs) noexcept : Disc_quote(std::move(rhs)){}

	Bulk_quote& operator=(const Bulk_quote&rhs)
	{
		if (this != &rhs)
			Disc_quote::operator=(rhs);
		return *this;
	}

	Bulk_quote&operator =(Bulk_quote&&rhs) noexcept
	{
		if (this != &rhs)
		{
			Disc_quote::operator=(std::move(rhs));
		}
		return *this;
	}

	double net_price(std::size_t n) const override
	{
		if (n >= quantity)
			return n*(1 - discount)*price;
		else
			return n*price;
	}
	//void debug() const override;

	 Bulk_quote* clone() const & { return new Bulk_quote(*this); }
	 Bulk_quote* clone() && {return new Bulk_quote(std::move(*this)); }
	~Bulk_quote() = default;

};


#endif//BULK_QUOTE_H
