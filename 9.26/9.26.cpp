#include <vector>
#include <list>
#include <iostream>
using namespace std;

int main()
{
	int ia[] = { 0,1,1,2,3,5,8,13,21,55,89 };
	vector<int> ivec(begin(ia), end(ia));//������begin()��end������������ָ��ͷ��β��Ԫ�ص�ָ�룻
	list<int> ilst(begin(ia), end(ia));//���ﱾ�����õ����������췶Χ����������Ҳ���ԣ�������������iteratorͷ�ļ���
	auto it = ilst.begin();
	auto vt = ivec.begin();
	while (it != ilst.end())
	{
		if (*it % 2)
			it = ilst.erase(it);//erase�������ص�����������ָԪ�صĺ�һ��Ԫ�صĵ�������
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
		cout << v <<" ";//����ֱ��ʹ��cout����������е�Ԫ��
	cout << endl;
	for (auto i : ilst)
		cout << i << " ";
	cout << endl;
	ivec.erase(ivec.begin(), ivec.begin());//�������Ƿ�Χ�ҷ�Χ��ȾͲ�ɾ��
	for (auto v : ivec)
		cout << v << " ";
	cout << '\n';
	system("pause");
	return 0;
}