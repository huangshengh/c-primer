#include <vector>
#include <list>
#include <iostream>
using namespace std;

int main()
{
	int ia[] = { 0,1,1,2,3,5,8,13,21,55,89 };
	vector<int> ivec(begin(ia), end(ia));//数组有begin()和end（）函数返回指向头和尾后元素的指针；
	list<int> ilst(begin(ia), end(ia));//这里本还是用迭代器来构造范围，但是这样也可以；这两个函数在iterator头文件中
	auto it = ilst.begin();
	auto vt = ivec.begin();
	while (it != ilst.end())
	{
		if (*it % 2)
			it = ilst.erase(it);//erase函数返回迭代器参数所指元素的后一个元素的迭代器；
		else
			++it;
	}
	while (vt != ivec.end() )
	{
		if (*vt % 2)
			++vt;
		else
			vt = ivec.erase(vt);
	}
	for (auto v : ivec)
		cout << v <<" ";//不能直接使用cout来输出类型中的元素
	cout << endl;
	for (auto i : ilst)
		cout << i << " ";
	cout << endl;
	ivec.erase(ivec.begin(), ivec.begin());//当参数是范围且范围想等就不删除
	for (auto v : ivec)
		cout << v << " ";
	cout << '\n';
	system("pause");
	return 0;
}