旧键盘上坏了几个键，于是在敲一段文字的时候，对应的字符就不会出现。现在给出应该输入的一段文字、以及实际被输入的文字，请你列出肯定坏掉的那些键。
输入格式：
输入在 2 行中分别给出应该输入的文字、以及实际被输入的文字。每段文字是不超过 80 个字符的串，由字母 A-Z（包括大、小写）、数字 0-9、以及下划线
_（代表空格）组成。题目保证 2 个字符串均非空。
输出格式：
按照发现顺序，在一行中输出坏掉的键。其中英文字母只输出大写，每个坏键只输出一次。题目保证至少有 1 个坏键。
输入样例：
7_This_is_a_test
_hs_s_a_es
输出样例：
7TI


#include <iostream>
#include <map>
#include <algorithm>
#include <string>
using namespace std;
	
int main()
{	
	map<char, int> mp;
	char s1[100], s2[100];
	cin >> s1 >> s2;
	for (int i = 0; s1[i]; ++i) {			//把s1都变成大写字母，map容器统计字符个数
		if (s1[i]>='a'&&s1[i]<='z')
			s1[i] = toupper(s1[i]);
		mp[s1[i]]++;
	}
	for (int i = 0; s2[i]; ++i) {			//s2也都变为大写字母方便比较，如果出现过了 次数置0
		if (s2[i] >= 'a'&&s2[i] <= 'z')
			s2[i] = toupper(s2[i]);
		mp[s2[i]] = 0;
	}
	for (int i = 0; s1[i]; ++i) {			//遍历s1，次数不是0的打印出来，次数置0避免重复打印 
		if (mp[s1[i]]) {
			cout << s1[i];
			mp[s1[i]] = 0;
		}
	}
}
