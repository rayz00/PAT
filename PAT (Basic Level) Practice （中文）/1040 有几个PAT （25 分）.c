字符串 APPAPT 中包含了两个单词 PAT，其中第一个 PAT 是第 2 位(P)，第 4 位(A)，第 6 位(T)；第二个 PAT 是第 3 位(P)，第 4 位(A)，第 6 位(T)。
现给定字符串，问一共可以形成多少个 PAT？
输入格式：
输入只有一行，包含一个字符串，长度不超过10^5，只包含 P、A、T 三种字母。
输出格式：
在一行中输出给定字符串中包含多少个 PAT。由于结果可能比较大，只输出对 1000000007 取余数的结果。
输入样例：
APPAPT
输出样例：
2


#include <iostream>
using namespace std;
	
int main()		
{	
	string s;
	cin >> s;
	int cnt1 = 0, cnt2 = 0, cnt3 = 0;
	for (int i = 0; s[i]; ++i) {
		if (s[i] == 'P')
			cnt1++;
		if (s[i] == 'A')
			cnt2 = (cnt1+cnt2)% 1000000007;
		if (s[i] == 'T')
			cnt3 = (cnt3+cnt2)% 1000000007;
	}
	cout << cnt3;
}	
