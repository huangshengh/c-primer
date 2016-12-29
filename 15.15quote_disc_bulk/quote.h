#ifndef Quote_h
#define Quote_h

#include <utility>
#include <string>
using std::string;


class quote
{
public:
	quote() = default;
	quote(const string&b,double p):bookno(b),price(p){}
	quote(const quote&rhs):bookno(rhs.bookno),price(rhs.price) {}
	quote(quote&&rhs) noexcept:bookno(rhs.bookno), price(rhs.price) {}
	quote& operator=(const quote&rhs)
	{
		if (this != &rhs)
		{
			bookno = rhs.bookno;
			price = rhs.price;
		}
		return *this;
	}

	quote& operator=(quote&&rhs) noexcept
	{
		if (this != &rhs)
		{
			bookno = rhs.bookno;
			price = rhs.price;
		}
		return *this;
	}

	string isbn() const { return bookno; }
	virtual double net_price(std::size_t n) const { return n*price; }
	virtual quote* clone() const & { return new quote(*this); }
	virtual quote* clone() && {return new quote(std::move(*this)); }

	virtual ~quote() = default;

private:
	string bookno;
protected:
	double price = 0.0;
};

#endif //Quote_h
