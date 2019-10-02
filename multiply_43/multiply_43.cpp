// multiply_43.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

string add(string s1, string s2)
{
	//进位
	int c = 0;
	int len1 = s1.size();
	int len2 = s2.size();
	int len = len1 > len2 ? len1 : len2;
	char *re = new char[len + 2];
	re[len + 1] = 0;
	int i = 0;
	while (i<len1&&i<len2)
	{
		int n = s1[len1 - i - 1] - '0' + s2[len2 - i - 1] - '0' + c;
		c = n / 10;
		n = n % 10;
		re[len - i] = n + '0';
		i++;
	}
	while (i<len1)
	{
		int n = s1[len1 - i - 1] - '0' + c;
		c = n / 10;
		n = n % 10;
		re[len - i] = n + '0';
		i++;
	}
	while (i < len2)
	{
		int n = s2[len2 - i - 1] - '0' + c;
		c = n / 10;
		n = n % 10;
		re[len - i] = n + '0';
		i++;
	}
	if (c)
	{
		re[0] = c + '0';
		string res = re;
		delete[]re;
		return res;
	}
	string res = re+1;
	delete[]re;
	return res;
}

string mult(string num1, char num2,int offset) {
	if (num2 == '0')return "0";
	if (num2=='1')
	{
		while (offset--)
		{
			num1.push_back('0');
		}
		return num1;
	}
	int num = num2 - '0';
	int c = 0;
	int len = num1.size();
	char *re = new char[len + 2];
	re[len + 1] = 0;
	string res;
	for (int i=len-1;i>=0;i--)
	{
		int n = (num1[i] - '0')*num + c;
		c = n / 10;
		n = n % 10;
		re[i + 1] = n + '0';
	}
	if (c)
	{
		re[0] = c + '0';
		res = re;
	}
	else
	{
		res = re + 1;
	}
	delete[]re;
	while (offset--)
	{
		res.push_back('0');
	}
	return res;
}

string multiply(string num1, string num2) {
	string res;
	int len1 = num1.size();
	int len2 = num2.size();
	if (len1<len2)
	{
		for (int i = 0; i < len1; i++)
		{
			string r = mult(num2, num1[len1 - i - 1], i);
			res = add(r, res);
		}
	}
	else
	{
		for (int i = 0; i < len2; i++)
		{
			string r = mult(num1, num2[len2 - i - 1], i);
			res = add(r, res);
		}
	}
	
	return res;
}

int main()
{
	string s1 = "111";
	string s2 = "96";
	cout << add(s1, s2)<<endl;
// 	cout << atoi(s1.c_str()) + atoi(s2.c_str()) << endl;
 //	cout << mult(s1, '2',0);
	cout << multiply(s1, s2);
    return 0;
}

