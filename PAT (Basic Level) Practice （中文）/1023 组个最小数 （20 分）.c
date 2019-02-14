给定数字 0-9 各若干个。你可以以任意顺序排列这些数字，但必须全部使用。目标是使得最后得到的数尽可能小（注意 0 不能做首位）。例如：给定两个 0，两个 1，
三个 5，一个 8，我们得到的最小的数就是 10015558。
现给定数字，请编写程序输出能够组成的最小的数。
输入格式：
输入在一行中给出 10 个非负整数，顺序表示我们拥有数字 0、数字 1、……数字 9 的个数。整数间用一个空格分隔。10 个数字的总个数不超过 50，且至少拥有 1 个
非 0 的数字。
输出格式：
在一行中输出能够组成的最小的数。
输入样例：
2 2 0 0 0 3 0 0 1 0
输出样例：
10015558

#include <iostream>
#include <algorithm>
using namespace std;
int main()
{	
	int A[10], B[50], t = 0;
	for (int i = 0; i < 10; ++i)
		cin >> A[i];
	for (int i = 0; i < 10; ++i) {
		while (A[i]--)
			B[t++] = i;
	}
	if (B[0] == 0) {
		for (int i = 0; i < t; ++i) {
			if (B[i]) {
				swap(B[0], B[i]);
				break;
			}
		}
	}
	for (int i = 0; i < t; ++i)
		cout << B[i];
}	


//python
s=list(map(int,input().split()))
#print(s)
point,out=0,[]
for i in range(10):
    for j in range(s[i]):
        out.append(i)
#print(out)
if 0 not in out:
    print(''.join(map(str,out)))
else:
#    print(out)
    for i in out:
        if i!=0:
            point=out.index(i)
            break
#    print(point)
    out[0],out[point]=out[point],out[0]
#    print(out)
    print(''.join(map(str,out)))
