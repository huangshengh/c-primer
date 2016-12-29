#include "ex14.05.h"

istream& operator >> (istream& in, Book&rhs)
{
	in >> rhs.no >> rhs.name >> rhs.author >> rhs.pubdate;
	return in;
}

ostream& operator<<(ostream&os, const Book&rhs)
{
	os << rhs.no << rhs.name << rhs.author << rhs.pubdate;
	return os;
}

bool operator==(const Book&lhs, const Book&rhs)
{
	return lhs.no == rhs.no;
}

bool operator != (const Book&lhs, const Book&rhs)
{
	return !(lhs == rhs);
}