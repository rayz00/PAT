一个数组A中存有N（N>0）个整数，在不允许使用另外数组的前提下，将每个整数循环向右移M（M>=0）个位置，即将A中的数据由（A0 A1……AN-1）变换为（AN-M …… AN-1 A0 A1……AN-M-1）
（最后M个数循环移至最前面的M个位置）。如果需要考虑程序移动数据的次数尽量少，要如何设计移动的方法？
输入格式：每个输入包含一个测试用例，第1行输入N ( 1<=N<=100)、M（M>=0）；第2行输入N个整数,之间用空格分隔。
输出格式：在一行中输出循环右移M位以后的整数序列，之间用空格分隔，序列结尾不能有多余空格。
输入样例：
6 2
1 2 3 4 5 6
输出样例：
5 6 1 2 3 4

//使用临时变量保存尾巴，所有元素右移一次，循环m次。 想法来自插入排序（取出特定位置的牌，插入到指定的位置）
#include <iostream>
using namespace std;	
int main()
{
	int n, m, A[100];
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> A[i];
	while (m--) {
		int temp = A[n - 1];
		for (int i = n - 1; i > 0; --i) 
			A[i] = A[i - 1];
		A[0] = temp;
	}
	for (int i = 0; i < n; ++i) {
		if (i)
			cout << ' ';
		cout << A[i];
	}
}

//如果用vecotr<int>，可以insert末元素到A.begin()，然后pop_back末元素
#include <iostream>
#include <vector>
using namespace std;	
int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> A(n);
	for (int i = 0; i < n; ++i)
		cin >> A[i];
	while (m--) {
		A.insert(A.begin(), A.back());
		A.pop_back();
	}
	cout << *A.begin();
	for (auto i=A.begin()+1; i!=A.end(); ++i) {
		cout << ' '<<*i;
	}
}



