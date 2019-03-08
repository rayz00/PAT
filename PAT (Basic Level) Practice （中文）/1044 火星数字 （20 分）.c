火星人是以 13 进制计数的：
地球人的 0 被火星人称为 tret。
地球人数字 1 到 12 的火星文分别为：jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec。
火星人将进位以后的 12 个高位数字分别称为：tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou。
例如地球人的数字 29 翻译成火星文就是 hel mar；而火星文 elo nov 对应地球数字 115。为了方便交流，请你编写程序实现地球和火星数字之间的互译。
输入格式：
输入第一行给出一个正整数 N（<100），随后 N 行，每行给出一个 [0, 169) 区间内的数字 —— 或者是地球文，或者是火星文。
输出格式：
对应输入的每一行，在一行中输出翻译后的另一种语言的数字。
输入样例：
4
29
5
elo nov
tam
输出样例：
hel mar
may
115
13


//python
s1=['tret','jan', 'feb', 'mar', 'apr', 'may', 'jun', 'jly', 'aug', 'sep', 'oct', 'nov', 'dec']
s2=[None,'tam', 'hel', 'maa', 'huh', 'tou', 'kes', 'hei', 'elo', 'syy', 'lok', 'mer', 'jou']
n=int(input())
s=[input() for i in range(n)]
def d_to_h(x):
    if x<=12:
        print(s1[x])
    elif x%13==0:
        print(s2[x//13])
    else:
        b=x%13
        a=int((x-b)/13)
        print(s2[a],s1[b])
def h_to_d(x):
    if ' 'in x:
        a,b=x.split()
        print(s2.index(a)*13+s1.index(b))
    elif x in s2:
        print(s2.index(x)*13)
    else:
        print(s1.index(x))
for i in range(len(s)):
    if s[i].isdigit():
        d_to_h(int(s[i]))
    else:
        h_to_d(s[i])
        
        

#include <iostream>
#include <algorithm>
using namespace std;

string s1[] = { "tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
string s2[] = { "####","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };

void E2M(int x) {
    if (x / 13 && x % 13)
        cout << s2[x / 13] << ' ' << s1[x % 13] << endl;
    else if (x % 13)
        cout << s1[x % 13] << endl;
    else if(x/13)
        cout << s2[x / 13] << endl;
    else
        cout<<"tret"<<endl;
}

void M2E(string s) {
    string l = s.substr(0, 3), r;
    if (s.size() > 4) {
        r = s.substr(4);
    }
    int t1, t2, t3;            //t1表示个位，t2表示高位
    for (t1 = 12; t1 > 0 && s1[t1].substr(0,3) != r; --t1);
    for (t2 = 12; t2 > 0 && s1[t2].substr(0,3) != l; --t2);
    for (t3 = 12; t3 > 0 && s2[t3] != l; --t3);
    cout << t3 * 13 + t1+ t2  << endl;
}

int main()		
{	
    int n;
    string s;
    cin >> n;
    getchar();
    while (n--) {
        getline(cin, s);
        if(isdigit(s[0]))
            E2M(stoi(s));
        else if(isalpha(s[0]))
            M2E(s);
        
    }
}
