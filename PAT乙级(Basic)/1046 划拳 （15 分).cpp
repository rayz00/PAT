#include "pch.h"
#include <iostream>
#include <map>	
#include <algorithm>
#include <string>
#include <list>	
#include <vector>
using namespace std;

int main()		
{	
	int n, cnta = 0, cntb = 0, a, b, c, d;
	cin >> n;
	while (n--) {
		cin >> a >> b >> c >> d;
		a += c;
		if (b == a && d != a)
			cntb++;
		else if (d == a && b != a)
			cnta++;
	}
	cout << cnta << ' ' << cntb;
}	

