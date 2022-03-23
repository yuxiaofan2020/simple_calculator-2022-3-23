#include"head.h"
map<char, int> smap = {
	{'*',3},
	{'/',3},
	{'+',2},
	{'-',2},
	{'(',1}
};//�洢��������ȼ�

//�ո��ȥ��
void Despace(string& s)
{
	int index = 0;
	if (!s.empty())
	{
		//���ַ����еĿո��ַ�����ɾ��
		while ((index = s.find(' ', index)) != string::npos)
		{
			s.erase(index, 1);
		}
	}
}

//��׺���ʽת��׺��ע�ⷵ��ֵΪvector
vector<string> Convert(string& s)
{

	vector<string> v;//ת�������������
	stack<char> sstack;//��תջ
	string nums = "0123456789";
	string oper_ = "+-*/()";
	string st = ""; //��ת�ַ���
	for (int i = 0; i < s.size(); i++)
	{
		if (nums.find(s[i]) != string::npos)
		{
			st = st + s[i];
			if (oper_.find(s[i + 1]) != string::npos || s[i + 1] == NULL)
			{
				v.push_back(st);
				st = "";
			}
		}
		else if (s[i] == '(')
		{
			sstack.push(s[i]);
		}
		else if (s[i] == ')')
		{
			char temp = sstack.top();
			sstack.pop();
			if (temp != '(')
			{
				st = "";
				st = st + temp;
				v.push_back(st);
				temp = sstack.top();
				sstack.pop();
			}
		}
		else
		{
			while (sstack.empty() == false && smap[sstack.top()] >= smap[s[i]])
			{
				st = "";
				st = st + sstack.top();
				v.push_back(st);
				sstack.pop();
			}
			sstack.push(s[i]);
		}
	}
	while (sstack.empty() == false)
	{
		st = "";
		st = st + sstack.top();
		sstack.pop();
		v.push_back(st);
	}
	return v;
}

//�Ժ�׺���ʽ���м���
void Calculate(vector<string>& v)
{
	string st;
	int x, y, z;
	stack<string> sstack;
	string oper_ = "+-*/";
	for (int i = 0; i < v.size(); i++)
	{
		if (oper_.find(v[i]) != string::npos)
		{
			x = std::stoi(sstack.top());
			sstack.pop();
			y = std::stoi(sstack.top());
			sstack.pop();
			if (v[i] == "+")
			{
				z = x + y;
				st = to_string(z);
				sstack.push(st);
			}
			else if (v[i] == "-")
			{
				z = x - y;
				st = to_string(z);
				sstack.push(st);
			}
			else if (v[i] == "*")
			{
				z = x * y;
				st = to_string(z);
				sstack.push(st);
			}
			else if (v[i] == "/")
			{
				z = x / y;
				st = to_string(z);
				sstack.push(st);
			}
		}
		else
		{
			sstack.push(v[i]);//��string���͵�����ѹ��ջ��
		}
	}
	st = sstack.top();
	cout << st;
}
