给定一个长度不超过 10^4的、仅由英文字母构成的字符串。请将字符重新调整顺序，按 PATestPATest.... 这样的顺序输出，并忽略其它字符。当然，六种字符的个数不一定是一样多的，
若某种字符已经输出完，则余下的字符仍按 PATest 的顺序打印，直到所有字符都被输出。
输入格式：
输入在一行中给出一个长度不超过 10^4的、仅由英文字母构成的非空字符串。
输出格式：
在一行中按题目要求输出排序后的字符串。题目保证输出非空。
输入样例：
redlesPayBestPATTopTeePHPereatitAPPT
输出样例：
PATestPATestPTetPTePePee



//python
s=input()
a=s.count('P')
b=s.count('A')
c=s.count('T')
d=s.count('e')
e=s.count('s')
f=s.count('t')
m=max([a,b,c,d,e,f])
def align(x,y):
    if x==0:
        return ['' for i in range(m)]
    elif x==m:
        return [y for i in range(m)]
    else:
        n=[y for i in range(x)]
        for i in range(x,m):
            n.append('')
        return n
for i in range(m):
    print(''.join([align(a,'P')[i],align(b,'A')[i],align(c,'T')[i],align(d,'e')[i],align(e,'s')[i],align(f,'t')[i]]),end='')



//c
#include <iostream>
#include <map>	
#include <algorithm>
#include <string>
#include <list>	
#include <vector>
using namespace std;

int main()		
{	
	string s;
	cin >> s;
	map<char, int> mp;
	for (int i = 0; s[i]; ++i)
		mp[s[i]]++;
	int max = 0;
	for (auto i : mp)
		if (i.second > max)
			max = i.second;
	for (int i = 0; i < max; ++i) {
		if (mp['P'] > i)
			cout << 'P';
		if (mp['A'] > i)
			cout << 'A';
		if (mp['T'] > i)
			cout << 'T';
		if (mp['e'] > i)
			cout << 'e';
		if (mp['s'] > i)
			cout << 's';
		if (mp['t'] > i)
			cout << 't';
	}
}

