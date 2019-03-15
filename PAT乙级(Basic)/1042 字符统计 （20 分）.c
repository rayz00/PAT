请编写程序，找出一段给定文字中出现最频繁的那个英文字母。
输入格式：
输入在一行中给出一个长度不超过 1000 的字符串。字符串由 ASCII 码表中任意可见字符及空格组成，至少包含 1 个英文字母，以回车结束（回车不算在内）。
输出格式：
在一行中输出出现频率最高的那个英文字母及其出现次数，其间以空格分隔。如果有并列，则输出按字母序最小的那个字母。统计时不区分大小写，输出小写字母。
输入样例：
This is a simple TEST.  There ARE numbers and other symbols 1&2&3...........
输出样例：
e 7


//python
s=sorted(list(filter(lambda x:x.isalpha(),list(input().lower()))))#生成顺序排列的字母列表
r,t=[],[]
for i in range(len(s)):#改变序列，变成【字母，次数】的组合
    if s[i] not in s[:i]:
        t.append([s[i],s.count(s[i])])
for i in t:             #找出最大次数的位置
    r.append(i[1])
point=r.index(max(r))
print(t[point][0],t[point][1])  #打印字母和最大次数


#include <iostream>
using namespace std;

int main()		
{	
	string s;
	getline(cin, s);
	int cnt[128] = { 0 }, max = 0;
	for (int i = 0; s[i]; ++i) {
		s[i] = tolower(s[i]);
		if(isalpha(s[i]))
			cnt[s[i]]++;
	}
	int index = 0;
	for (int i = 0; i < 128; ++i) {
		if (cnt[i] > max) {
			index = i;
			max = cnt[i];
		}
	}
	printf("%c %d", index, cnt[index]);
}	
