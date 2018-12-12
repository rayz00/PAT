读入一个正整数 n，计算其各位数字之和，用汉语拼音写出和的每一位数字。
输入格式：
每个测试输入包含 1 个测试用例，即给出自然数 n 的值。这里保证 n 小于 10的100次方。
输出格式：
在一行内输出 n 的各位数字之和的每一位，拼音数字间有 1 空格，但一行中最后一个拼音数字后没有空格。
输入样例：
1234567890987654321123456789
输出样例：
yi san wu
/*字符串和数字的转换，用循环拆解数字
*/
//C
#include<stdio.h>	
#include<string.h>
int main()
{
	char s[100];	//不可用char *s定义字符串 因为指针没有指向有效的内存可能非法。
	scanf("%s", s); 
//	gets(s);	  PAT的C(gcc)编译器不支持gets()函数，但是C(clang)支持甚至自带常用头文件,如stdio.h和string.h
	const char book[][5] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu" };	//对照表使用const，可用二维数组（第二个数字表示字符串长度）或指针数组表示字符串列表。
//	const char *book[] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu" };	
	int sum = 0;
	for (int i = 0; i < strlen(s); ++i)
		sum += s[i] - '0';
	int t=0,result[10] = { 0 };	//C风格拆解数字的方法
	while (sum) {
		result[t++] = sum % 10;
		sum /= 10;
	}
	for (int i = t - 1; i >= 0; --i) {	//倒序输出
		printf("%s", book[result[i]]);
		if (i != 0)
			printf(" ");
	}
}

//C++ 直接使用字符串类型
#include<iostream>	
#include<string>
using namespace std;

int main()
{
	string s;	//使用string类型
	cin >> s;
	string book[] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu" };
	int sum = 0;
	for (int i = 0; s[i]; ++i)
		sum += s[i] - '0';
//	for (auto i : s)	//C++11
//		sum += i - '0';						
	string tmp = to_string(sum);	//数字转为字符串
	for (int i = 0; tmp[i]; ++i) {	//遍历字符串
		if (i)
			cout << ' ';
		cout << book[tmp[i] - '0'];
	}
}
