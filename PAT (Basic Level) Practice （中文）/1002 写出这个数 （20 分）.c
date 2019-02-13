读入一个正整数 n，计算其各位数字之和，用汉语拼音写出和的每一位数字。
输入格式：
每个测试输入包含 1 个测试用例，即给出自然数 n 的值。这里保证 n 小于 10的100次方。
输出格式：
在一行内输出 n 的各位数字之和的每一位，拼音数字间有 1 空格，但一行中最后一个拼音数字后没有空格。
输入样例：
1234567890987654321123456789
输出样例：
yi san wu

//C 字符串，拆整数
#include<stdio.h>	
#include<string.h>
int main()
{
	char s[100];		//scanf输入需要确切的地址，char *s不行。因为指针没有指向有效的内存可能非法，不能开辟内存空间
	scanf("%s", s);
	const char *book[] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu" };
	//注意指针数组和字符串数组的区别。字符串数组直接存储字符串内容，而指针数组只存地址，该地址指向字符串常量，字符串本身不在该数组里。
	//指针数组必须加const才能类型一致指向字符串常量，可以初始化和赋值（指针重指向），不可输入（不可修改字符串常量）。
	//字符串数组（char book[][10],const char book[][10]）可以初始化和cin scanf输入，不可用字符串常量赋值。加const后只可scanf输入，不可cin输入。
	int sum = 0;				//求和  	
	for (int i = 0; s[i]; ++i)
		sum += s[i] - '0';
	int t=0,result[10] = { 0 };		//拆数字存到数组，也可以拆成其他进制
	while (sum) {
		result[t++] = sum % 10;
		sum /= 10;
	}
	for (int i = t - 1; i >= 0; --i) {	//格式化输出需要一个辅助量，利用头尾或循环变量i或者单独定义一个flag
		printf("%s", book[result[i]]);  
		if (i != 0)
			printf(" ");
	}
}

//C++ 字符串，库函数
#include<iostream>	
#include<string>
using namespace std;
int main()
{
	string s;
	cin >> s;
	string book[] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu" };
	int sum = 0;
	for (auto i : s) 			//求和 
		sum += i - '0';
	string tmp = to_string(sum);		//int转string库函数
	for (int i = 0; tmp[i]; ++i) {
		if (i)
			cout << ' ';
		cout << book[tmp[i] - '0'];
	}
}
