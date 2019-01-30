 正整数A的“DA（为1位整数）部分”定义为由A中所有DA组成的新整数PA。例如：给定A = 3862767，DA = 6，则A的“6部分”PA是66，因为A中有2个6。
现给定A、DA、B、DB，请编写程序计算PA + PB。
输入格式：
输入在一行中依次给出A、DA、B、DB，中间以空格分隔，其中0 < A, B < 10^10。
输出格式：
在一行中输出PA + PB的值。
输入样例1：
3862767 6 13530293 3
输出样例1：
399
输入样例2：
3862767 1 13530293 8
输出样例2：
0

//c 作为int处理，拆整数和组合数字
#include <iostream>
using namespace std;
int main() 
{	
	int A, da, B, db, t1 = 0, t2 = 0;
	cin >> A >> da >> B >> db;
	while (A) {
		if (A % 10 == da)
			t1 = t1*10 + da;
		A /= 10;
	}
	while (B) {
		if (B % 10 == db)
			t2 = t2 * 10 + db;
		B /= 10;
	}
	cout << (t1 + t2);
}	

//c++ 作为string处理
#include <iostream>
using namespace std;
int trans(string s, char c) {           //把A转为PA
	string t;
	int sum=0;
	int k = 0;
	for (auto i : s) {                    //生成目标字符串
		if (i == c)
			t += c;
	}
	for (int i = 0;t[i];++i)              //字符串变为整数
		sum = sum * 10 + (t[i] - '0');

//	for (auto ite = t.rbegin();ite != t.rend();++ite)
//		sum += (*ite - '0')*pow(10, k++);

	return sum;
}

int main()
{
	string a, b;
	char c, d;
	cin >> a >> c >> b >> d;
//	cout << trans(a, c) << endl << trans(b, d) << endl;
	
		cout << trans(a, c) + trans(b, d);	
}
