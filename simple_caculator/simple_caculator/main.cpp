#include"head.h"

int main()
{
	string s;
	vector<string> v;
	cout << "��������������ʽ�ӣ�";
	//������������ʽ���ַ���
	getline(cin, s);
	//ȥ���ո�
	Despace(s);
	//ת��Ϊ��׺���ʽ
	v = Convert(s);
	//�Ժ�׺���ʽ���м���
	Calculate(v);
	getchar();
	return 0;
}
