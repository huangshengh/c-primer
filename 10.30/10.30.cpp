#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
	istream_iterator<int> in(cin), eof;
	vector<int>vec;
	while (in!=eof)
		//�ص���push_back�����istream_iterator��Ҫ����������һ���Ҫ����������ֱ��ʹ��
		vec.push_back(*in++);
	sort(vec.begin(), vec.end());
	ostream_iterator<int>out(cout, " ");
	for (const auto c : vec)
		*out++ = c;
	cout << endl;
	system("pause");
	return 0;
}