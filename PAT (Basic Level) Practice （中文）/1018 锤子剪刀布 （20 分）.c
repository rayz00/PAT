大家应该都会玩“锤子剪刀布”的游戏：两人同时给出手势，胜负规则如图所示：
现给出两人的交锋记录，请统计双方的胜、平、负次数，并且给出双方分别出什么手势的胜算最大。
输入格式：
输入第1行给出正整数N（<=105），即双方交锋的次数。随后N行，每行给出一次交锋的信息，
即甲、乙双方同时给出的的手势。C代表“锤子”、J代表“剪刀”、B代表“布”，第1个字母代表甲方，
第2个代表乙方，中间有1个空格。
输出格式：
输出第1、2行分别给出甲、乙的胜、平、负次数，数字间以1个空格分隔。第3行给出两个字母，
分别代表甲、乙获胜次数最多的手势，中间有1个空格。如果解不唯一，则输出按字母序最小的解。
输入样例：
10
C J
J B
C B
B B
B C
C C
C B
J B
B C
J J
输出样例：
5 3 2
2 3 5
B B

//使用函数分离判断过程，选择合适的结构存储结果（选择数组和map容器），使用map要当心
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int judge(char a, char b) {
	if (a == b)
		return 0;
	if ((a == 'C'&&b == 'J') || (a == 'J'&&b == 'B') || (a == 'B'&&b == 'C'))
		return 1;
	else
		return -1;
}

int main() 
{	
	char a, b;
	int n, cnta[3] = { 0 }, cntb[3] = {0};		//cnt[0][1][2]代表胜平负
	map<char, int> mpa = { { 'J',0 }, {'C',0},{'B',0} };    //map作为树形有序容器，默认按key值升序排列，而非定义的顺序。实际的存储顺序是BCJ
	map<char, int> mpb = { { 'J',0 }, {'C',0},{'B',0} };
	cin >> n;
	while (n--) {
		cin >> a >> b;
		if (judge(a, b) > 0) {
			cnta[0]++;
			cntb[2]++;
			mpa[a]++;
		}
		else if (judge(a, b) < 0) {
			cnta[2]++;
			cntb[0]++;
			mpb[b]++;
		}
		else {
			cnta[1]++;
			cntb[1]++;
		}
	}
  //寻找mpa和mpb的最大值
	char x = 'B', y = 'B';      //所以x y的初始值应该为B。
	int t1 = 0, t2 = 0;
	for (auto i : mpa) {
		if (i.second > t1) {      //我开始以为map可以按照定义顺序排列为JCB，定义x y为J，判断条件写>=，这是错误的。
			x = i.first;
			t1 = i.second;
		}
	}
	for (auto i : mpb) {
		if (i.second > t2) {
			y = i.first;
			t2 = i.second;
		}
	}
	printf("%d %d %d\n%d %d %d\n%c %c", cnta[0], cnta[1], cnta[2], cntb[0], cntb[1], cntb[2], x, y);
}	
