输入两个非负10进制整数A和B(<=2^30-1)，输出A+B的D (1 < D <= 10)进制数。
输入格式：
输入在一行中依次给出3个整数A、B和D。
输出格式：
输出A+B的D进制数。
输入样例：
123 456 8
输出样例：
1103

//拆数字，这么快就来了，注意和为0的边界情况。
#include <iostream>
using namespace std;
int main()
{	
	int A, B, D;
	cin >> A >> B >> D;
	int n = A + B, result[100] = { 0 }, t = 0;
	if (n == 0) {
		cout << 0;
		return 0;
	}
	while (n) {
		result[t++] = n % D;
		n /= D;
	}
	for (int i = t-1; i >= 0; --i)
		cout << result[i];
}



//python
A,B,D=list(map(int,input().split()))
def transfer(x,y):
    s=[]
    while x>0:
        s.append(x%y)
        x=x//y
    return ''.join(list(map(str,s[::-1])))
if A==B==0:
    print(0)
else:
    print(transfer((A+B),D))
