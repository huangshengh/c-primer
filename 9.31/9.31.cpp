#include <iostream>
#include <forward_list>
#include <iterator>
using namespace std;

int main()
{
	forward_list<int> lst{ 0,1,2,3,4,5,6,7,8,9 };
	auto iter = lst.begin();
	auto iter1 = lst.before_begin();//Ҫ������iter֮ǰ��λ��
	while (iter != lst.end())
	{
		if (*iter % 2)//���������
		{
			iter = lst.insert_after(iter, *iter);//����iter֮����룬���ҷ��ز����Ǹ�Ԫ�صĵ�����
			++iter;//ָ��Ԫ�б�����һ��Ԫ��
			++iter1;
			++iter1;//�����ͱ���iter1ʼ����iterǰ�棬ɾ����ʱ�����ʹ�á�iter + n���ֲ���ֻ����vector��string��ʹ�� 
		}
		else
		{
	     //��Ϊerase_after�����ɾ��������֮���Ԫ�أ�����������Ҫһ����ɾԪ��֮ǰ�ĵ�����������iter�����ã�������Ҫ����������
			iter = lst.erase_after(iter1);//���ص��Ǳ�ɾԪ��֮��,����ɾ��������Ԫ����ôiter��ָ��ԭ���ĵڶ���Ԫ�أ���ʱiter1
			//����ָ����Ԫ�أ�ԭ���ĵڶ���Ԫ�ر������Ԫ�أ������������������������޸���
			//�����������ɾ����Ԫ����ôiter1��Ҫ�ı䣬Ҫ����ʼ�ձ�ʾiter֮ǰ�Ǹ�Ԫ�صĵ�����
		}
	}
	for (auto c : lst)
		cout << c << " ";
	cout << endl;
	system("pause");
	return 0;
}