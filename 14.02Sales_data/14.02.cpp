#include "14.02.h"

Sales_data::Sales_data(std::istream &is):Sales_data()
{
	is >> *this;
}


Sales_data& Sales_data::operator+=(const Sales_data &rhs)
{
	if (isbn() != rhs.isbn())
		throw isbn_mismatch("wrong isbns", isbn(), rhs.isbn());
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

istream& operator >> (istream& is, Sales_data &item)
{
	double price;
	is >> item.bookNo >> item.units_sold >> price;
	if (is)
		item.revenue = price*item.units_sold;
	else
		item = Sales_data();
	return is;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;
	sum += rhs;
	return sum;
}

ostream &operator<<(ostream&os, const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
	return os;
}

Sales_data& Sales_data::operator=(const string&isbn)
{
	*this = Sales_data(isbn);
	return *this;
}

int main()
{
	Sales_data item1, item2,sum;
	item1="123456789";
	item2 = "987654321";
	try
    {
			 sum = item1 + item2;
	}
	catch (const isbn_mismatch& e)
	{
			std::cerr << e.what() << ": left isbn(" << e.left << ") right isbn(" << e.right << ")" << std::endl;
	}
	system("pause");
	return 0;
}