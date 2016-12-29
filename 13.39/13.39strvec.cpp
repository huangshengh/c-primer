#define _SCL_SECURE_NO_WARNINGS

#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <initializer_list>
#include <algorithm>

using std::allocator;
using std::string;

class StrVec
{
public:
	StrVec():elements(nullptr),first_free(nullptr),cap(nullptr){}//进行默认初始化，没有使用allocator类来分配内存

	StrVec(std::initializer_list<string> lst)//使用不知数量的string花括号来初始化
	{
		auto newdata = alloc_n_copy(lst.begin(), lst.end());
		elements = newdata.first;
		first_free = cap = newdata.second;
	}

	StrVec(const StrVec&);//拷贝构造函数

	StrVec &operator=(const std::initializer_list<string>&);//话括号内的元素进行赋值

	StrVec& operator=(const StrVec&);//拷贝赋值运算符

	StrVec(StrVec &&s) noexcept :elements(s.elements), first_free(s.first_free), cap(s.cap)
	{
		s.elements = s.first_free = s.cap = nullptr;
	}//移动构造函数

	StrVec&operator=(StrVec &&rhs) noexcept//移动赋值运算符
	{
		if (this != &rhs)
		{
			free();
			elements = rhs.elements;
			first_free = rhs.first_free;
			cap = rhs.cap;
			rhs.elements = rhs.first_free = rhs.cap = nullptr;
		}
		return *this;
	}

	~StrVec();
	//重载下标运算符，一个常量和非常量
	string &operator[](size_t n)
	{
		return elements[n];
	}

	const string&operator[](size_t n) const
	{
		return elements[n];
	}

	void push_back(const string &s);

	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - first_free; }
	string* begin() const { return elements; }
	string * end() const { return first_free; }
	void reserve(size_t n);

private:
    allocator<string> alloc;//被用来分配内存
	//保证至少有一个新元素的空间，不然的话重新分配
	void chk_n_alloc()
	{
		if (size() == capacity())
			reallocate();
	}
	std::pair<string*, string*>alloc_n_copy(const string*, const string*);
	std::pair<string*, string*>movealloc_n_copy(const string*, const string*);
	void free();
	void reallocate();
	string* elements;
	string* first_free;
	string* cap;
};

void StrVec::push_back(const string&s)
{
	chk_n_alloc();//检查有没有足够的空间，没有就申请
	alloc.construct(first_free++, s);//在原来first_free的地方构建s，，然后first一项下一个位置
}


std::pair<string*, string*> StrVec::alloc_n_copy(const string *b, const string *e)
{
	auto data = alloc.allocate(e-b);//data是指向未分配内存的一个指针,计算需要分配的内存大小
	return{ data,uninitialized_copy(b,e,data) };//uninitialized_copy这个算法是用迭代器b，e的范围内容拷贝到data指向的位分配的内存
                                               //uninitialized_copy 返回的是指向最后一个构造的元素之后的位置
}


void StrVec::free()
{
	if (elements)
	{

		for_each(elements, first_free, [this](string &p) {return alloc.destroy(&p); });
		//for (auto p = first_free; p != elements; --p)
			//alloc.destroy(p);//删除分配的内存上的数据
		alloc.deallocate(elements, cap - elements);//销毁分配的内存，elements必须是一个先前allocate返回的指针，这个n得是先前创建的大小
	}
}

StrVec::StrVec(const StrVec& rhs)
{
	auto newdata = alloc_n_copy(rhs.begin(), rhs.end());//调用这个函数是分配的空间刚好够
	elements = newdata.first;
	first_free = cap = newdata.second;
}

StrVec::~StrVec()
{
	free();
}

StrVec& StrVec::operator=(const StrVec&s)//拷贝赋值运算符跟拷贝构造函数差不多啊。
{
	auto data = alloc_n_copy(s.begin(), s.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}




void StrVec::reallocate()
{
	auto newcapacity = size() ? 2 * size() : 1;
	auto newdata = alloc.allocate(newcapacity);
	auto dest = newdata;//这个newdata还得保持新内存开始的地方
	auto elem = elements;
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));//把旧的数据move到新的内存中
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}

void StrVec::reserve(size_t n)
{
	auto newcapacity = n;
	auto newdata = alloc.allocate(newcapacity);
	auto dest = newdata;//这个newdata还得保持新内存开始的地方
	auto elem = elements;
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));//把旧的数据move到新的内存中
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}

StrVec& StrVec::operator=(const std::initializer_list<string> &il)
{
	auto data = alloc_n_copy(il.begin(), il.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	std::cout << "haha" << std::endl;
	return *this;
}



int main()
{
	StrVec v1,v2;
	v1 = { "ni","hao","kan" };
	v2 = v1;
	const StrVec v3(v1);
	if (v1.size() && v1[0].empty())
	{
		v1[0] = "wo";
	}
	system("pause");
	return 0;
}