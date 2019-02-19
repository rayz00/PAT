给定一个常数 K 以及一个单链表 L，请编写程序将 L 中每 K 个结点反转。例如：给定 L 为 1→2→3→4→5→6，K 为 3，则输出应该为 3→2→1→6→5→4；如果 K 为 4，
则输出应该为 4→3→2→1→5→6，即最后不到 K 个元素不反转。
输入格式：
每个输入包含 1 个测试用例。每个测试用例第 1 行给出第 1 个结点的地址、结点总个数正整数 N (≤10^5)、以及正整数 K (≤N)，即要求反转的子链结点的个数。
结点的地址是 5 位非负整数，NULL 地址用 −1 表示。
接下来有 N 行，每行格式为：
Address Data Next
其中 Address 是结点地址，Data 是该结点保存的整数数据，Next 是下一结点的地址。
输出格式：
对每个测试用例，顺序输出反转后的链表，其上每个结点占一行，格式与输入相同。
输入样例：
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
输出样例：
00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999
99999 5 68237
68237 6 -1
  
  
//思维误区：开始我总想着创建链表，把这些节点都塞进去操作。还纠结要不要用STL的list容器，这样实在很难搞。
//按照这题输入的方式，首先要使用数组把输入存起来，再捋出链表，再排序。从头到尾都是数组，压根没链表
#include <iostream>
#include <algorithm>
using namespace std;

struct node{
    int addr;
    int data;
    int next;
}L[100000],*result[100000];            //L存输入，result指针数组捋出链表

int main()
{
    int A,N,K;
    cin>>A>>N>>K;
    for(int i=0;i<N;++i){
        node tmp;
        cin>>tmp.addr>>tmp.data>>tmp.next;
        L[tmp.addr]=tmp;
    }
    int t=0;                          //链表的实际长度不一定=N
    for(int i=A;i!=-1;i=L[i].next){
        result[t++]=&L[i];
    }
    for(int i=0;i<t-t%K;i+=K){
        reverse(result+i,result+i+K);
    }
    for(int i=0;i<t-1;++i)
        printf("%05d %d %05d\n",result[i]->addr,result[i]->data,result[i+1]->addr);
    printf("%05d %d -1",result[t-1]->addr,result[t-1]->data);
}
