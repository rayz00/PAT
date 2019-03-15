令Pi表示第i个素数。现任给两个正整数M <= N <= 10^4，请输出PM到PN的所有素数。
输入格式：
输入在一行中给出M和N，其间以空格分隔。
输出格式：
输出从PM到PN的所有素数，每10个数字占1行，其间以空格分隔，但行末不得有多余空格。
输入样例：
5 27
输出样例：
11 13 17 19 23 29 31 37 41 43
47 53 59 61 67 71 73 79 83 89
97 101 103

//素数筛,格式化输出（统计在素数表里的位置，以及在打印表里的位置）
#include <iostream>
using namespace std;
int prime[1000000];	//0表示素数 1表示非素数
int main() 
{	
	for (int i = 2; i < 1000000; ++i)
		if (!prime[i])
			for (int j = i + i; j < 1000000; j += i)
				prime[j] = 1;
	int m, n, cnt = 0, p = 0;     //cnt表示在素数表里的位置，关系到n和m；p表示在打印表的里位置，逢10换行；末元素单独处理
	cin >> m >> n;
	for (int i = 2; i < 1000000; ++i) {
		if (!prime[i]) {
			cnt++;
			if (cnt >= m && cnt < n) {
				p++;
				if (p % 10)
					cout << i << ' ';
				else
					cout << i << endl;
			}
			else if (cnt == n) {
				cout << i;
				return 0;
			}
		}
	}
}	







//python    不是正确的程序，思路是生成素数序列，留作以后修改
def _odd_iter():
    n = 1
    while True:
        n = n + 2
        yield n
def _not_divisible(n):
    return lambda x: x % n > 0
def primes():
    yield 2
    it = _odd_iter() # 初始序列
    while True:
        n = next(it) # 返回序列的第一个数
        yield n
        it = filter(_not_divisible(n), it) # 构造新序列
# 打印1000以内的素数:
for n in primes():
    if n < 1000:
        print(n)
    else:
        break
