本题要求你写个程序把给定的符号打印成沙漏的形状。例如给定17个“*”，要求按下列格式打印
*****
 ***
  *
 ***
*****
所谓“沙漏形状”，是指每行输出奇数个符号；各行符号中心对齐；相邻两行符号数差2；符号数先从大到小顺序递减到1，再从小到大顺序递增；首尾符号数相等。
给定任意N个符号，不一定能正好组成一个沙漏。要求打印出的沙漏能用掉尽可能多的符号。
输入格式:
输入在一行给出1个正整数N（≤1000）和一个符号，中间以空格分隔。
输出格式:
首先打印出由给定符号组成的最大的沙漏形状，最后在一行中输出剩下没用掉的符号数。
输入样例:
19 *
输出样例:
*****
 ***
  *
 ***
*****
2


#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
  int N;
    char s;
  cin >> N >> s;
  int n=1;
    while ((n + 1)*(n + 1) / 2 - 1 <= N){
      n += 2;
    }
  n = n - 2;
  vector<string> clock;
  for (int i = 0;i < (n-1)/2;++i)clock.push_back(string(i, ' ') + string(n-2*i, s));
  for (auto i = clock.begin();i != clock.end();++i)cout << *i << endl;
  cout << string((n - 1) / 2, ' ') + string(1,s) << endl;
  for (auto i = clock.rbegin();i != clock.rend();++i)cout << *i << endl;
  cout <<N-((n + 1)*(n + 1) / 2 - 1)<<endl;
    return 0;
}
