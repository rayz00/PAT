科学计数法是科学家用来表示很大或很小的数字的一种方便的方法，其满足正则表达式 [+-][1-9].[0-9]+E[+-][0-9]+，即数字的整数部分只有 1 位，小数部分至少
有 1 位，该数字及其指数部分的正负号即使对正数也必定明确给出。
现以科学计数法的格式给出实数 A，请编写程序按普通数字表示法输出 A，并保证所有有效位都被保留。
输入格式：
每个输入包含 1 个测试用例，即一个以科学计数法表示的实数 A。该数字的存储长度不超过 9999 字节，且其指数的绝对值不超过 9999。
输出格式：
对每个测试用例，在一行中按普通数字表示法输出 A，并保证所有有效位都被保留，包括末尾的 0。
输入样例 1：
+1.23400E-03
输出样例 1：
0.00123400
输入样例 2：
-1.2E+10
输出样例 2：
-12000000000

//分割字符串。我太纠结于用c风格字符串来做，没有想到c++的分割和转换函数
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
	
int main()
{	
	string s;
	cin >> s;
	int i = 0;
	while (s[i] != 'E')
		i++;
	string l = s.substr(1, i-1);	//substr左右参数都是闭区间
	string r = s.substr(i + 1);
	int n = stoi(r);				      //对应to_string
	if (s[0] == '-')
		cout << '-';
	if (n < 0) {                  //如果指数为负
		cout << "0.";
		for (int k = 0; k < abs(n) - 1; ++k)
			cout << '0';
		for (int k = 0; l[k]; ++k)
			if (l[k] != '.')
				cout << l[k];
	}
	else {
		cout << l[0];               //指数为正
		if (n >= l.size() - 2) {	  //如果没有小数点
			for (int j = 2; l[j]; ++j)
				cout << l[j];
			for (int j = 0; j < n - l.size() + 2; ++j)
				cout << 0;
		}
		else {
			int j;	                  //如果还有小数点
			for (j = 2; j < n + 2; ++j)
				cout << l[j];		        //打印小数点前
			cout << '.';
			for (; l[j]; ++j)		      //打印小数点后
				cout << l[j];
		}
	}
}	
