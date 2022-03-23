#pragma once
#ifndef HEAD_H_
#define HEAD_H_
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <map>

using namespace std;

//空格的去除
void Despace(string& s);
//中缀表达式转后缀
vector<string> Convert(string& s);
//对后缀表达式进行计算
void Calculate(vector<string>& s);

#endif
