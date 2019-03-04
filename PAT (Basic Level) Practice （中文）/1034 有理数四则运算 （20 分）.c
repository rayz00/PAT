本题要求编写程序，计算 2 个有理数的和、差、积、商。
输入格式：
输入在一行中按照 a1/b1 a2/b2 的格式给出两个分数形式的有理数，其中分子和分母全是整型范围内的整数，负号只可能出现在分子前，分母不为 0。
输出格式：
分别在 4 行中按照 有理数1 运算符 有理数2 = 结果 的格式顺序输出 2 个有理数的和、差、积、商。注意输出的每个有理数必须是该有理数的最简形式 k a/b，
其中 k 是整数部分，a/b 是最简分数部分；若为负数，则须加括号；若除法分母为 0，则输出 Inf。题目保证正确的输出中没有超过整型范围的整数。
输入样例 1：
2/3 -4/2
输出样例 1：
2/3 + (-2) = (-1 1/3)
2/3 - (-2) = 2 2/3
2/3 * (-2) = (-1 1/3)
2/3 / (-2) = (-1/3)
输入样例 2：
5/3 0/6
输出样例 2：
1 2/3 + 0 = 1 2/3
1 2/3 - 0 = 1 2/3
1 2/3 * 0 = 0
1 2/3 / 0 = Inf


#include <iostream>
#include <algorithm>
using namespace std;

long gcd(long m,long n) {
	return m % n == 0 ? n: gcd(n, m%n);
}
	
void format(long long x, long long y) {
	if (y == 0) {
		printf("Inf");
		return;
	}
	int t = gcd(abs(x), abs(y));
	x /= t;
	y /= t;
	if (x*y < 0)
		printf("(-");
	if (abs(x) / abs(y) > 0 && abs(x) % abs(y) > 0)
		printf("%lld %lld/%lld", abs(x) / abs(y), abs(x) % abs(y), abs(y));
	else if (abs(x) % abs(y) > 0)
		printf("%lld/%lld", abs(x), abs(y));
	else
		printf("%lld", abs(x) / abs(y));
	if (x*y < 0)
		printf(")");
}	
	
int main()		
{	
	long long a, b, c, d;
	scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d);
	format(a, b); printf(" + "); format(c, d); printf(" = "); format(a*d + b * c, b*d); printf("\n");
	format(a, b); printf(" - "); format(c, d); printf(" = "); format(a*d - b * c, b*d); printf("\n");
	format(a, b); printf(" * "); format(c, d); printf(" = "); format(a*c, b*d); printf("\n");
	format(a, b); printf(" / "); format(c, d); printf(" = "); format(a*d, b*c); printf("\n");
}
