#include"head.h"

int main()
{
	string s;
	vector<string> v;
	cout << "请输入四则运算式子：";
	//输入四则运算式子字符串
	getline(cin, s);
	//去除空格
	Despace(s);
	//转换为后缀表达式
	v = Convert(s);
	//对后缀表达式进行计算
	Calculate(v);
	getchar();
	return 0;
}
