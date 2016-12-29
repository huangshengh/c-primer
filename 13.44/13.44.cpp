#include <iostream>
#include <memory>
#include <algorithm>
#include <vector>


using std::allocator;  
using std::vector;
using std::ostream;
using std::istream;
using std::for_each;
using std::size_t;

class String
{
	friend bool operator<(const String&, const String&);
	friend bool operator==(const String&, const String&);
	friend bool operator!=(const String&, const String&);
	friend ostream& operator<<(ostream&, const String&);
public:
	String() :elements(nullptr), last_elem(nullptr) {}

	String(const char*rhs);

	String(const String&);

	String& operator=(const String&);

	String(String&&s) noexcept:elements(s.elements), last_elem(s.last_elem)
	{
		s.elements = s.last_elem = nullptr;
		std::cout << "move" << std::endl;
	}

	String& operator=(String &&s)
	{
		if (this != &s)
		{
			free();
			elements = s.elements;
			last_elem = s.last_elem;
			s.elements = s.last_elem = nullptr;
		}
		return *this;
	}

	~String();
	char&operator[](size_t n)
	{
		return elements[n];
	}

	const char&operator [](size_t n) const
	{
		return elements[n];
	}
	char* begin() const { return elements; }
	char* end() const { return last_elem; }
	const char* c_str() const { return elements; }
	size_t size() const { return last_elem - elements; }
	size_t length() const { return last_elem - elements - 1; }
private:
	char* elements;
	char* last_elem;
	allocator<char> alloc;
	std::pair<char*, char*>alloc_n_copy(const char*, const char*);
	void range_initializer(const char*, const char*);
	void free();
};

std::pair<char*, char*> String::alloc_n_copy(const char*b, const char*e)
{
	auto str = alloc.allocate(e - b + 1);
	return{ str,std::uninitialized_copy(b,e,str) };
}//这个函数负责申请空间，将迭代器的东西拷贝到空间里

void String::range_initializer(const char*first, const char*last_elem)
{
	auto newstr = alloc_n_copy(first, last_elem);
	elements = newstr.first;
	last_elem = newstr.second;
}//负责提供迭代器，提供范围。然后初始化成员

String::String(const char*s)
{
	char *s1 = const_cast<char*>(s);
	while (*s1)
		++s1;
	range_initializer(s, ++s1);
}//用char*的时候重要的是要拷贝的范围，但是指针也是一个迭代器

String::String(const String& rhs)
{
	range_initializer(rhs.elements, rhs.last_elem);
	std::cout << "copy construct" << std::endl;
}

void String::free()
{
	if (elements)
	{
		std::for_each(elements, last_elem, [this](char&c) {alloc.destroy(&c); });
		alloc.deallocate(elements, size());
	}
}

String::~String()
{
	free();
}

String& String::operator=(const String&s)
{
	auto newdata = alloc_n_copy(s.elements, s.last_elem);
	free();
	elements = newdata.first;
	last_elem = newdata.second;
	std::cout << "copy-assignment" << std::endl;
	return *this;
}

//并不需要一个成员来保存string那一块地方。有两个指向空间头尾的指针就可以，并不需要把空间也放在类里。

ostream& operator<<(ostream& os, const String& s)
{
	char* c = const_cast<char*>(s.elements);
	while (*c)
		os << *c++;
	return os;
}

bool operator==(const String&a, const String&b)
{ 
	return (a.size() == b.size() && std::equal(a.begin(), a.end(), b.begin()));
}

bool operator!=(const String&a, const String&b)
{
	return !(a == b);
}

bool operator<(const String&lhs , const String&rhs)
{
	/*if (a != b)
	{
        for (auto f = a.begin(); f != a.end(); ++f)
			{
				auto c = b.begin();
				if (*f - *c > 0)
				{
					return 0;
					break;
				}
				else if (*f - *c == 0)
				{
					++c;
					continue;
				}
				if (*f - *c < 0)
				{
					return 1;
					break;
				}
			}
		
	}
	else
		return a == b;*/

	return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}


int main()
{
	vector<String> str;
	String s1 = "nihao"; 
	String s2("wohao");
	String s3 = "haoa";
	std::cout << s1[3] << std::endl;
//	str.push_back(s1);
//	str.push_back(s2);
	system("pause");
	return 0;
}