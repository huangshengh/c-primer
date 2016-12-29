#ifndef DISC_H
#define DISC_H

#include "quote.h"
class Disc_quote :public quote
{public:
	Disc_quote();
	Disc_quote(const string& b, double p,size_t q,double d):
		quote(b,p),quantity(q),discount(d){}
	Disc_quote(const Disc_quote&rhs):quote(rhs),quantity(rhs.quantity),discount(rhs.discount){}
	Disc_quote(Disc_quote&&rhs) noexcept:quote(std::move(rhs)),quantity(rhs.quantity),discount(rhs.discount){}

	Disc_quote& operator=(const Disc_quote&rhs)
	{
		if (this != &rhs)
		{
			quote::operator=(rhs);
			quantity = rhs.quantity;
			discount = rhs.discount;

		}
		return *this;
	}

	Disc_quote& operator=(Disc_quote&&rhs)noexcept
	{
		if (this != &rhs)
		{
			quote::operator=(std::move(rhs));
			quantity = rhs.quantity;
			discount = rhs.discount;
		}
		return *this;
	}
	virtual double net_price(size_t n) const override = 0;
	~Disc_quote() = default;
protected:
	std::size_t quantity=0;
	double discount = 0.0;
};


#endif//DISC_H
