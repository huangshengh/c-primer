#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
	list<int> l;
	fill_n(back_inserter(l), 10, 0);//��������back_insert����Ϊl�ǿ�����������ʹ��back_insert������һ��������������push_back����ֵ
	for (auto c : l)
		cout << c << " ";
	cout << endl;
	system("pause");
	return 0;
}