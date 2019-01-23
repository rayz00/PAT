让我们定义 dn 为：dn = pn+1 - pn，其中 pi 是第i个素数。显然有 d1=1 且对于n>1有 dn 是偶数。“素数对猜想”认为“存在无穷多对相邻且差为2的素数”。
现给定任意正整数N (< 105)，请计算不超过N的满足猜想的素数对的个数。
输入格式：每个测试输入包含1个测试用例，给出正整数N。
输出格式：每个测试用例的输出占一行，不超过N的满足猜想的素数对的个数。
输入样例：
20
输出样例：
4

//素数筛
#include <iostream>
using namespace std;	
int main()
{		
	int n, prime[100000] = {0};		//0表示素数，1表示非素数
	scanf("%d", &n);
	for (int i = 2; i <= n; ++i)
		if (!prime[i])
			for (int j = i + i; j <= n; j += i)
				prime[j] = 1;
	int cnt = 0;
	for (int i = 2; i <= n - 2; ++i)
		if (!prime[i] && !prime[i + 2])
			cnt++;
	printf("%d\n", cnt);
}

//函数判断素数
#include <iostream>
#include <math.h>
using namespace std;	
bool isprime(int x) {
	if (x <= 1)
		return false;
	for (int i = 2; i*i <= x; ++i)	//或者i<=sqrt(x);
		if (x%i == 0)
			return false;
	return true;
}
int main()
{		
	int n, cnt = 0;
	cin >> n;
	for (int i = 2; i <= n - 2; ++i)
		if (isprime(i) && isprime(i + 2))
			cnt++;
	cout << cnt;
}

//另一种统计素数对的方法
#include <iostream>
using namespace std;
int main() {
	int n, prime[100000] = { 0 };		//0表示素数，1表示非素数
	scanf("%d", &n);
	for (int i = 2; i <= n; ++i)
		if (!prime[i])
			for (int j = i + i; j <= n; j += i)
				prime[j] = 1;
	int cnt = 0;
	int pre = 2;
	for (int i = 3; i <= n; ++i)
		if (!prime[i]) {
			if (i - pre == 2)
				cnt++;
			pre = i;
		}
	printf("%d", cnt);
}


