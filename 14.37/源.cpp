#include <iostream>
#include <vector>
#include <algorithm>

class IsEqual {
	int value;
public:
	IsEqual(int v) : value(v) { }
	bool operator()(int elem) {
		return elem == value;
	}
};

int main()
{
	std::vector<int> vec = { 3, 2, 1, 4, 3, 7, 8, 6 };
	std::replace_if(vec.begin(), vec.end(), IsEqual(3), 5);//这个算法用第四个参数替换掉满足第三个条件的数据。  
	for (int i : vec) std::cout << i << " ";
	std::cout << std::endl;
	system("pause");
	return 0;
}
