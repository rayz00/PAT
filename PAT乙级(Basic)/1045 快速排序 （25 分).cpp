#include "pch.h"
#include <iostream>
#include <map>	
#include <algorithm>
#include <string>
#include <list>	
#include <vector>
using namespace std;

int n, A[100000], lmax[100000], rmin[100000], cnt = 0;

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> A[i];
	for (int i = 0, max = i; i < n; ++i)
		lmax[i] = A[i] >= A[max] ? A[max = i] : A[max];
	for (int i = n - 1, min = i; i >= 0; --i)
		rmin[i] = A[i] <= A[min] ? A[min = i] : A[min];
	for (int i = 0; i < n; ++i) {
		if (A[i] == lmax[i] && A[i] == rmin[i])
			cnt++;
		else
			A[i] = 0;
	}
	cout << cnt << endl;
	for (int i = 0; i < n && cnt; i++) if (A[i])
		printf("%d%c", A[i], --cnt ? ' ' : '\0');
	printf("\n");
}