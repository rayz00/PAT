给定一系列正整数，请按要求对数字进行分类，并输出以下5个数字：
A1 = 能被5整除的数字中所有偶数的和；
A2 = 将被5除后余1的数字按给出顺序进行交错求和，即计算n1-n2+n3-n4...；
A3 = 被5除后余2的数字的个数；
A4 = 被5除后余3的数字的平均数，精确到小数点后1位；
A5 = 被5除后余4的数字中最大数字。
输入格式：
每个输入包含1个测试用例。每个测试用例先给出一个不超过1000的正整数N，
随后给出N个不超过1000的待分类的正整数。数字间以空格分隔。
输出格式：
对给定的N个正整数，按题目要求计算A1~A5并在一行中顺序输出。
数字间以空格分隔，但行末不得有多余空格。
若其中某一类数字不存在，则在相应位置输出“N”。
输入样例1：
13 1 2 3 4 5 6 7 8 9 10 20 16 18
输出样例1：
30 11 2 9.7 9
输入样例2：
8 1 2 4 5 6 7 9 16
输出样例2：
N 11 2 N 9


//分支循环，多种运算
#include <iostream>
using namespace std;
	
int main() 
{	
	int n, t,A1=0,A2[1000],cnt=0,A3=0,A4=0,cnt4=0,max=0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> t;
		if (t % 5 == 0 && t % 2 == 0)
			A1 += t;
		else if (t % 5 == 1)
			cnt % 2 == 0 ? A2[cnt++] = t : A2[cnt++] = -t;
		else if (t % 5 == 2)
			A3++;
		else if (t % 5 == 3) {
			A4 += t;
			cnt4++;
		}
		else if (t % 5 == 4) {
			if (t > max) {
				max = t;
			}
		}
	}
	if (A1 == 0) {
		cout << 'N';
	}
	else
		cout << A1;
	if (cnt == 0)
		cout << ' ' << 'N';
	else {
		int sum = 0;
		for (int i = cnt - 1; i >= 0; --i)
			sum += A2[i];
		cout << ' ' << sum;
	}
	if (A3 == 0)
		cout << ' ' << 'N';
	else
		cout << ' ' << A3;
	if (A4 == 0)
		cout << ' ' << 'N';
	else {
		printf(" %.1f", A4*1.0 / cnt4);
	}
	if (max == 0) {
		cout << ' ' << 'N';
	}
	else {
		cout << ' ' << max;
	}
}	




//python
s=list(map(int,input().split()))
s.remove(s[0])
if len([i for i in s if i%2==0 and i%5==0])==0:
    A1='N'
else:
    A1 = sum([i for i in s if i % 2 == 0 and i % 5 == 0])
if len([i for i in s if i%5==1])==0:
    A2='N'
else:
    A2 = sum([i for i in s if i % 5 == 1][::2]) - sum([i for i in s if i % 5 == 1][1::2])
if len([i for i in s if i%5==2])==0:
    A3='N'
else:
    A3=len([i for i in s if i%5==2])
if len([i for i in s if i%5==3])==0:
    A4='N'
else:
    A4=round(sum([i for i in s if i%5==3])/float(len([i for i in s if i%5==3])),1)\
if len([i for i in s if i%5==4])==0:
    A5 = 'N'
else:
    A5=max([i for i in s if i%5==4])
print(' '.join(str(i) for i in [A1,A2,A3,A4,A5]))
