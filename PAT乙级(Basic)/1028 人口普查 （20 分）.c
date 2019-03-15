某城镇进行人口普查，得到了全体居民的生日。现请你写个程序，找出镇上最年长和最年轻的人。
这里确保每个输入的日期都是合法的，但不一定是合理的——假设已知镇上没有超过 200 岁的老人，而今天是 2014 年 9 月 6 日，所以超过 200 岁的生日和未出生的
生日都是不合理的，应该被过滤掉。
输入格式：
输入在第一行给出正整数 N，取值在(0,10^5]；随后 N 行，每行给出 1 个人的姓名（由不超过 5 个英文字母组成的字符串）、以及按 yyyy/mm/dd（即年/月/日）格
式给出的生日。题目保证最年长和最年轻的人没有并列。
输出格式：
在一行中顺序输出有效生日的个数、最年长人和最年轻人的姓名，其间以空格分隔。
输入样例：
5
John 2001/05/12
Tom 1814/09/06
Ann 2121/01/30
James 1814/09/05
Steve 1967/11/20
输出样例：
3 Tom John


//坑点是没有结果的情况 输出0，就不输出名字了
#include <iostream>
#include <string>
using namespace std;
  
int main()
{	
	int n, cnt = 0;
	string name, birthday, old = "1814/09/06", young = "2014/09/06", name1, name2;
	cin >> n;
	while (n--) {
		cin >> name >> birthday;
		if (birthday >= "1814/09/06"&&birthday <= "2014/09/06") {
			if (birthday <= young) {
				young = birthday;
				name2 = name;
			}
			if (birthday >= old) {
				old = birthday;
				name1 = name;
			}
			cnt++;
		}
	}
	if (cnt)
		cout << cnt << ' ' << name2 << ' ' << name1;
	else
		cout << 0;
}



//python
n=int(input())
s=dict(input().split() for i in range(n))
c,max,min,max_name,min_name=0,'2014/09/06','1814/09/06','',''
for k,v in s.items():
    if '1814/09/06'<=v<='2014/09/06':
        c+=1
        if v>min:
            min=v
            min_name=k
        if v<max:
            max=v
            max_name=k
if c==0:
    print(0)
else:
    print(c,max_name,min_name)
