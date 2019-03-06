本题要求读入 N 名学生的成绩，将获得某一给定分数的学生人数输出。
输入格式：
输入在第 1 行给出不超过 10^5 的正整数 N，即学生总人数。随后一行给出 N 名学生的百分制整数成绩，中间以空格分隔。最后一行给出要查询的分数个数 K（不超过 N 的正整数），随后是 K 个
分数，中间以空格分隔。
输出格式：
在一行中按查询顺序给出得分等于指定分数的学生人数，中间以空格分隔，但行末不得有多余空格。
输入样例：
10
60 75 90 55 75 99 82 90 75 50
3 75 90 88
输出样例：
3 2 0


#include <iostream>
using namespace std;
	
int main()		
{	
	int n, k, A[101] = { 0 };
	scanf("%d", &n);
	while (n--) {
		scanf("%d",&k);
		A[k]++;
	}
	cin >> k;
	while (k--) {
		scanf("%d", &n);
		printf("%d%c", A[n], k == 0 ? '\0' : ' ');
	}
}


n=int(input())
m=list(map(int,input().split()))
k=list(map(int,input().split()))
s=[]
for i in range(1,len(k)):
    s.append(m.count(k[i]))
print(' '.join([str(i) for i in s]))


#include <iostream>
#include <map>	
using namespace std;
	
int main()		
{	
	int n, k;
	map<int, int> mp;
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &k);
		mp[k]++;
	}
	scanf("%d", &k);
	while (k--) {
		scanf("%d", &n);
		printf("%d%c", mp[n], k == 0 ? '\0' : ' ');
	}
}
