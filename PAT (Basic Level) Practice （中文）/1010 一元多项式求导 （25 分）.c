设计函数求一元多项式的导数。（注：xn（n为整数）的一阶导数为n*xn-1。）
输入格式：以指数递降方式输入多项式非零项系数和指数（绝对值均为不超过1000的整数）。数字间以空格分隔。
输出格式：以与输入相同的格式输出导数多项式非零项的系数和指数。数字间以空格分隔，但结尾不能有多余空格。注意“零多项式”的指数和系数都是0，但是表示为“0 0”。
输入样例：
3 4 -5 2 6 1 -2 0
输出样例：
12 3 -10 1 6 0

//如果只有2项且指数是0，输出0 0
//否则输出n*x x-1，如果指数是0，舍弃该项
//理解题意有点难
#include <iostream>
using namespace std;
int main() 
{
	int x, n, flag = 0;
	while (cin >> x >> n) {
		if (!flag && !n)
			cout << 0 << ' ' << 0;
		if (n) {
			if (flag)
				cout << ' ';
			cout << x * n << ' ' << n - 1;
			flag = 1;
		}
	}
}

#include <iostream>
using namespace std;

int main() 
{
	int x, n, flag = 0;
	while (cin >> x >> n) {
		if (n) {
			if (flag)
				cout << ' ';
			cout << x * n << ' ' << n - 1;
			flag = 1;
		}
		if (!flag)
			cout << 0 << ' ' << 0;
	}
}

//python
s=list(map(int,input().split()))    //自动输入一行
if len(s)>2 and s[-1]==0:           //观察末元素，如果项数>2，舍弃末项
    del s[-2:]
if len(s)==2 and s[-1]==0:          //如果只有2项，且指数0，输出0 0
    print('0 0')
else:                               //已经舍弃指数0项了，按照规则改变序列的值，最后加空格输出
    rayz=list(range(len(s)))
    for i in range(int(len(s)/2)):
        rayz[2*i]=s[2*i]*s[2*i+1]
        rayz[2*i+1]=s[2*i+1]-1
    print(' '.join(str(i) for i in rayz))
