#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <cstdlib>

using std::fstream;
using std::cout;
using std::cin;
using std::cin;
using std::cerr;
using std::endl;
using std::string;

int main()
{
	fstream inout("D:\\t.txt", fstream::ate | fstream::in | fstream::out);//�Զ�д�ķ�ʽ���ļ������Ҷ�λ���ļ�β��
	if (!inout)//��֤��û�д򿪳ɹ�
	{
		cerr << "unable to open file" << endl;
		system("pause");
		return EXIT_FAILURE;
	}
	auto end_mark = inout.tellg();//��סĿǰ�����ļ�β�Ķ�ȡλ��
	inout.seekg(0, fstream::beg);//����ȡλ�ö�λ���ļ��п�ʼλ��
	size_t cnt = 0;//�ֽ����ۼ���
	string line;//��ȡ��line��
	while (inout&&inout.tellg() != end_mark&&getline(inout, line))//û�г��ִ����һ����Զ�ȡ��һ��
	{
		cnt += line.size() + 1;//ÿ��ѭ����ʱ���ۻ�ÿһ�е��ֽ�����+1��ָ�������Ļ��з���
		auto mark = inout.tellg();//��ס���ڵĶ�ȡλ�ã���Ȼ��֪�����ڵĶ�ȡλ��������
		inout.seekp(0, fstream::end);//�����λ�ö�λ���ļ�β��
		inout << cnt;//���ļ�βд�����ݣ�ÿ�ε�����cnt�ͻ����ÿ��line���ֽ���
		if (mark != end_mark)//�������λ�û�ζ���ļ�β������ļ�β�Ǹտ�ʼ��βλ�ã���Ϊ���ļ�д������
			//�ļ�β��λ�ÿ϶��������ı�
			inout << " ";//�����������֮�����һ���� ��������һ�����ֱ��־���
		inout.seekg(mark);//cntд���ļ�֮�󣬽�����λ�ûָ���������һ�ε�ѭ��
	}
	inout.seekp(0, fstream::end);//ѭ����������λ����ʱ������ĩβ
	inout << "\n";//���ļ�ĩβд�뻻�С�����
	system("pause");
	return 0;
}