#include<iostream>
#include <string>

using std::string;

class HasPtr
{
public:
	friend void swap(HasPtr&, HasPtr&);
	HasPtr(const string &s=string()):ps(new string(s)),i(0){}
	HasPtr(const HasPtr &hp):ps(new string(*hp.ps)),i(hp.i){}
	HasPtr& operator=(const HasPtr &hp)
	{
		auto new_p = new string(*hp.ps);
		delete ps;
		ps = new_p;
		i = hp.i;
		return *this;
	}

	HasPtr(HasPtr&&rhs) noexcept:ps(rhs.ps), i(rhs.i)
	{
		rhs.ps = nullptr;
	}

	HasPtr& operator=(HasPtr rhs)
	{
		swap(*this, rhs);
		return *this;
	}

	~HasPtr()
	{
		delete ps;
	}

	void show() { std::cout << *ps << std::endl; }
private:
	string* ps;
	int i;

};

inline void swap(HasPtr& lhs, HasPtr& rhs)
{
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
	std::cout << "call swap" << std::endl;
}

int main()
{
	string a = "good";
	string b = "bad";
	HasPtr f(a);
	HasPtr r(b);
	swap(f, r);
	system("pause");
	return 0;
}