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
	fstream inout("D:\\t.txt", fstream::ate | fstream::in | fstream::out);//以都写的方式打开文件，并且定位到文件尾；
	if (!inout)//验证有没有打开成功
	{
		cerr << "unable to open file" << endl;
		system("pause");
		return EXIT_FAILURE;
	}
	auto end_mark = inout.tellg();//记住目前处于文件尾的读取位置
	inout.seekg(0, fstream::beg);//将读取位置定位到文件夹开始位置
	size_t cnt = 0;//字节数累加器
	string line;//读取到line中
	while (inout&&inout.tellg() != end_mark&&getline(inout, line))//没有出现错误，且还可以读取下一行
	{
		cnt += line.size() + 1;//每次循环的时候，累积每一行的字节数，+1是指看不见的换行符；
		auto mark = inout.tellg();//记住现在的读取位置，索然不知道现在的读取位置是哪里
		inout.seekp(0, fstream::end);//将输出位置定位到文件尾；
		inout << cnt;//想文件尾写入数据，每次迭代后，cnt就会加上每次line的字节数
		if (mark != end_mark)//如果读的位置还味道文件尾，这个文件尾是刚开始的尾位置，因为向文件写入数据
			//文件尾的位置肯定会有所改变
			inout << " ";//就在这个数字之后加入一个“ ”，和下一个数字保持距离
		inout.seekg(mark);//cnt写进文件之后，将读的位置恢复，进行下一次的循环
	}
	inout.seekp(0, fstream::end);//循环结束，定位到此时真正的末尾
	inout << "\n";//在文件末尾写入换行。结束
	system("pause");
	return 0;
}