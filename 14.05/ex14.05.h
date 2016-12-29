#ifndef CP5_CH14_EX14_05_H
#define CP5_CH14_EX14_05_H

#include <iostream>
#include <string>

using std::istream;
using std::ostream;
using std::string;

class Book
{
	friend istream& operator >> (istream&, Book&);
	friend ostream& operator<<(ostream&, const Book&);
	friend bool operator==(const Book&, const Book&);
	friend bool operator!=(const Book&, const Book&);

public:
	Book() = default;
	Book(unsigned no,string name,string author,string pubdate):no(no),name(name),author(author),pubdate(pubdate){}
	Book(istream &in) { in >> *this; }
private:
	unsigned no;
	string name;
	string author;
	string pubdate;
};

istream& operator >> (istream&, Book&);
ostream& operator<<(ostream&, const Book&);
bool operator==(const Book&, const Book&);
bool operator!=(const Book&, const Book&);

#endif // CP5_CH14_EX14_05_H
