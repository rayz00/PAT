给定一个正整数数列，和正整数p，设这个数列中的最大值是M，最小值是m，如果M <= m * p，则称这个数列是完美数列。
现在给定参数p和一些正整数，请你从中选择尽可能多的数构成一个完美数列。
输入格式：
输入第一行给出两个正整数N和p，其中N（<= 10^5）是输入的正整数的个数，p（<= 10^9）是给定的参数。第二行给出N个正整数，每个数不超过109。
输出格式：
在一行中输出最多可以选择多少个数可以用它们组成一个完美数列。
输入样例：
10 8
2 3 20 4 5 1 6 7 8 9
输出样例：
8

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{	
	int N, p, v[100000], max = 0, first = 0, last = 0;
	cin >> N >> p;
	for (int i = 0; i < N; ++i)
		cin >> v[i];
	sort(v, v + N);
	for (; last < N; ++first) {
		while (last < N&&v[last] <= 1L * v[first] * p)
			last++;
		if (last - first > max)
			max = last - first;
	}
	cout << max;
}


