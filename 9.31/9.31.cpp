#include <iostream>
#include <forward_list>
#include <iterator>
using namespace std;

int main()
{
	forward_list<int> lst{ 0,1,2,3,4,5,6,7,8,9 };
	auto iter = lst.begin();
	auto iter1 = lst.before_begin();//要保持在iter之前的位置
	while (iter != lst.end())
	{
		if (*iter % 2)//如果是奇数
		{
			iter = lst.insert_after(iter, *iter);//是在iter之后插入，并且返回插入那个元素的迭代器
			++iter;//指向元列表中下一个元素
			++iter1;
			++iter1;//这样就保持iter1始终在iter前面，删除的时候可以使用。iter + n这种操作只能在vector和string中使用 
		}
		else
		{
	     //因为erase_after这个是删除迭代器之后的元素，所以我们需要一个被删元素之前的迭代器，——iter不能用，所以需要两个迭代器
			iter = lst.erase_after(iter1);//返回的是被删元素之后,假设删除的是首元素那么iter就指向原来的第二个元素，此时iter1
			//还是指向首元素，原来的第二个元素变成了首元素；所以这两个迭代器都不用修改吗？
			//但是如果不是删除首元素那么iter1就要改变，要保持始终表示iter之前那个元素的迭代器
		}
	}
	for (auto c : lst)
		cout << c << " ";
	cout << endl;
	system("pause");
	return 0;
}