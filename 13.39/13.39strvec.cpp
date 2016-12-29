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
	StrVec():elements(nullptr),first_free(nullptr),cap(nullptr){}//����Ĭ�ϳ�ʼ����û��ʹ��allocator���������ڴ�

	StrVec(std::initializer_list<string> lst)//ʹ�ò�֪������string����������ʼ��
	{
		auto newdata = alloc_n_copy(lst.begin(), lst.end());
		elements = newdata.first;
		first_free = cap = newdata.second;
	}

	StrVec(const StrVec&);//�������캯��

	StrVec &operator=(const std::initializer_list<string>&);//�������ڵ�Ԫ�ؽ��и�ֵ

	StrVec& operator=(const StrVec&);//������ֵ�����

	StrVec(StrVec &&s) noexcept :elements(s.elements), first_free(s.first_free), cap(s.cap)
	{
		s.elements = s.first_free = s.cap = nullptr;
	}//�ƶ����캯��

	StrVec&operator=(StrVec &&rhs) noexcept//�ƶ���ֵ�����
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
	//�����±��������һ�������ͷǳ���
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
    allocator<string> alloc;//�����������ڴ�
	//��֤������һ����Ԫ�صĿռ䣬��Ȼ�Ļ����·���
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
	chk_n_alloc();//�����û���㹻�Ŀռ䣬û�о�����
	alloc.construct(first_free++, s);//��ԭ��first_free�ĵط�����s����Ȼ��firstһ����һ��λ��
}


std::pair<string*, string*> StrVec::alloc_n_copy(const string *b, const string *e)
{
	auto data = alloc.allocate(e-b);//data��ָ��δ�����ڴ��һ��ָ��,������Ҫ������ڴ��С
	return{ data,uninitialized_copy(b,e,data) };//uninitialized_copy����㷨���õ�����b��e�ķ�Χ���ݿ�����dataָ���λ������ڴ�
                                               //uninitialized_copy ���ص���ָ�����һ�������Ԫ��֮���λ��
}


void StrVec::free()
{
	if (elements)
	{

		for_each(elements, first_free, [this](string &p) {return alloc.destroy(&p); });
		//for (auto p = first_free; p != elements; --p)
			//alloc.destroy(p);//ɾ��������ڴ��ϵ�����
		alloc.deallocate(elements, cap - elements);//���ٷ�����ڴ棬elements������һ����ǰallocate���ص�ָ�룬���n������ǰ�����Ĵ�С
	}
}

StrVec::StrVec(const StrVec& rhs)
{
	auto newdata = alloc_n_copy(rhs.begin(), rhs.end());//������������Ƿ���Ŀռ�պù�
	elements = newdata.first;
	first_free = cap = newdata.second;
}

StrVec::~StrVec()
{
	free();
}

StrVec& StrVec::operator=(const StrVec&s)//������ֵ��������������캯����డ��
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
	auto dest = newdata;//���newdata���ñ������ڴ濪ʼ�ĵط�
	auto elem = elements;
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));//�Ѿɵ�����move���µ��ڴ���
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}

void StrVec::reserve(size_t n)
{
	auto newcapacity = n;
	auto newdata = alloc.allocate(newcapacity);
	auto dest = newdata;//���newdata���ñ������ڴ濪ʼ�ĵط�
	auto elem = elements;
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));//�Ѿɵ�����move���µ��ڴ���
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