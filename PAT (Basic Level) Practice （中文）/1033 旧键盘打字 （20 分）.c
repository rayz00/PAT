旧键盘上坏了几个键，于是在敲一段文字的时候，对应的字符就不会出现。现在给出应该输入的一段文字、以及坏掉的那些键，打出的结果文字会是怎样？
输入格式：
输入在 2 行中分别给出坏掉的那些键、以及应该输入的文字。其中对应英文字母的坏键以大写给出；每段文字是不超过 10^5个字符的串。可用的字符包括字母 [a-z, A-Z]、数字 0-9、以及下划线 _（代表空格）、,、.、-、+（代表上档键）。题目保证第 2 行输入的文字串非空。
注意：如果上档键坏掉了，那么大写的英文字母无法被打出。
输出格式：
在一行中输出能够被打出的结果文字。如果没有一个字符能被打出，则输出空行。
输入样例：
7+IE.
7_This_is_a_test.
输出样例：
_hs_s_a_tst

//ugly code没什么好的想法，按照定义做的  getline()是为了防止第一行为空 这个设定挺坑的
#include <iostream>
#include <string>
using namespace std;

int main()		
{
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	if (s1.find('+')!=-1) {
		for (int i = 0; s2[i]; ++i) {
			if (s2[i] >= 'A'&&s2[i] <= 'Z')
				continue;
			else if(isalpha(s2[i]))
				s2[i] = toupper(s2[i]);
			if (s1.find(s2[i])==-1) {
				if (isalpha(s2[i]))
					s2[i] = tolower(s2[i]);
				cout << s2[i];
			}
		}	
	}
	else {
		char t;
		for (int i = 0; s2[i]; ++i) {
			if (isalpha(s2[i])) {
				t = toupper(s2[i]);
				if (s1.find(t) == -1)
					cout << s2[i];
			}	
			else if (s1.find(s2[i]) == -1) {
				cout << s2[i];
			}
		}
	}
}	
