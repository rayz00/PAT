让我们用字母 B 来表示“百”、字母 S 表示“十”，用 12...n 来表示不为零的个位数字 n（<10），换个格式来输出任一个不超过 3 位的正整数。例如 234 应该被输出为 BBSSS1234，因为它有 2 个“百”、3 个“十”、以及个位的 4。
输入格式：
每个测试输入包含 1 个测试用例，给出正整数 n（<1000）。
输出格式：
每个测试用例的输出占一行，用规定的格式输出 n。
输入样例 1：
234
输出样例 1：
BBSSS1234
输入样例 2：
23
输出样例 2：
SS123
//取出输入数的百位，十位，个位。就是循环的次数。
#include <iostream>
using namespace std;	
int main()
{		
	int n, a = 0, b = 0, c = 0;
	cin >> n;
	c = n % 10;
	n /= 10;
	b = n % 10;
	n /= 10;
	a = n % 10;
	for (int i = 0; i < a; ++i)
		cout << 'B';
	for (int i = 0; i < b; ++i)
		cout << 'S';
	for (int i = 1; i <= c; ++i) {
		cout << i;
	}
}	

//通用拆数字的方法
#include <iostream>
using namespace std;	
int main()
{		
	int n, N[3] = {0},t = 0;
	cin >> n;
	while (n) {
		N[t++] = n % 10;
		n /= 10;
	}
	while (N[2]--)
		cout << 'B';
	while (N[1]--)
		cout << 'S';
	for (int i = 1; i <= N[0]; ++i)
		cout << i;
}

//python
s=list(input())
s=[int(item) for item in s]
m=['1','2','3','4','5','6','7','8','9']
def out_int(a):
    if 1<=a<=9:
        print(''.join(m[:a]),end='')
    else:
        pass
def out_S(b):
    if b==0:
        pass
    else:
        k=['S' for i in range(b)]
        print(''.join(k),end='')
def out_B(c):
    k = ['B' for i in range(c)]
    print(''.join(k), end='')

if len(s)==1:
    out_int(s[0])
elif len(s)==2:
    out_S(s[0])
    out_int(s[1])
else:
    out_B(s[0])
    out_S(s[1])
    out_int(s[2])
