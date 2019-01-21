读入一个正整数 n，计算其各位数字之和，用汉语拼音写出和的每一位数字。
输入格式：
每个测试输入包含 1 个测试用例，即给出自然数 n 的值。这里保证 n 小于 10的100次方。
输出格式：
在一行内输出 n 的各位数字之和的每一位，拼音数字间有 1 空格，但一行中最后一个拼音数字后没有空格。
输入样例：
1234567890987654321123456789
输出样例：
yi san wu

//C 	循环拆数字
#include<stdio.h>	
#include<string.h>
int main()
{
	char s[100];		//不可用char *s定义字符串 因为指针没有指向有效的内存可能非法。
	scanf("%s", s); 	//或者用gets(s)输入行。但PAT的C(gcc)编译器不支持gets()，C(clang)支持
	const char book[][5] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu" };	//可用二维数组（第二个数字表示字符串长度）或指针数组表示字符串列表const char *book[] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu" };	
	int sum = 0;
	for (int i = 0; s[i]; ++i)
		sum += s[i] - '0';
	int t=0,result[10] = { 0 };		//拆数字
	while (sum) {
		result[t++] = sum % 10;
		sum /= 10;
	}
	for (int i = t - 1; i >= 0; --i) {	//倒序遍历数组
		printf("%s", book[result[i]]);
		if (i != 0)
			printf(" ");
	}
}

//C++ 	字符串类型
#include<iostream>	
#include<string>
using namespace std;
int main()
{
	string s;
	cin >> s;
	string book[] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu" };
	int sum = 0;
	for (int i = 0; s[i]; ++i)		//C++ 11      for (auto i : s) sum += i - '0';
		sum += s[i] - '0';					
	string tmp = to_string(sum);		//int类型转换为字符串类型
	for (int i = 0; tmp[i]; ++i) {
		if (i)
			cout << ' ';
		cout << book[tmp[i] - '0'];
	}
}
