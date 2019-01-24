给定一句英语，要求你编写程序，将句中所有单词的顺序颠倒输出。
输入格式：
测试输入包含一个测试用例，在一行内给出总长度不超过 80 的字符串。字符串由若干单词和若干空格组成，其中单词是由英文字母（大小写有区分）组成的字符串，单词之间用 1 个空格分开，输入保证句子末尾没有多余的空格。
输出格式：
每个测试用例的输出占一行，输出倒序后的句子。
输入样例：
Hello World Here I Come
输出样例：
Come I Here World Hello

//虽然很简单的题目，但深挖有很多重要的基础知识
//pure c, strtok分隔字符串，保存每个隔断的指针在数组里，倒序输出。（使用c编译器，因为g++和clang++都不支持gets()了）
#include <stdio.h>
#include <string.h>
int main()
{
    char s[100];
    char *t[100];              //和char t[100][100]的区别
    gets(s);
    char *p=strtok(s," ");    //strtok的用法
    int cnt=0;
    while(p){
        t[cnt++]=p;
        p=strtok(NULL," ");
    }
    for(int i=cnt-1;i>0;--i)
        printf("%s ",t[i]);
    printf("%s",t[0]);
}

/*详细解释char s[100][100], char s*[100], char **s的区别
char s[100][100]存储的是字符数组，实际内容是{'a''b''c''c''\0','w''a''q''w''\0','w''q''q''d''\0'}这样，siezof(s[0])是100。s[0]确实是字符数组，
但是const char *类型，是不能用char *地址赋值的（注意：赋值不同于初始化，字符数组可以用字符串初始化，比如char s[20]="dwda",char s[100][100]=
{"dwad","dwqdq","aaaa“}）。
在c中，字符串"dqwdq",char s[20]的返回值都是char *类型的地址，并不能把地址赋值给字符数组（数组名都是常量指针）。这里我们希望有一个字符串数组保存隔
的值，char s[100][100]并不能用字符串地址赋值。

char *s[100]是指针数组，存储的是地址，实际内容是{0076D24C 0076D24C 0076D24C}这样，查看sizeof(s[0],s[1],s[2],s[3])都是4。字符串的返回值都是一个
地址(string类型返回值不是地址，比如string t="212",t就是string类型，而非地址)。所以char *s[100]这样的指针数组能接收字符串地址。实际的字符串内容保
存在其他地方,而char s[100][100]把字符串保存在自己内部。

char **s:不能定义二位数组，因为指针指向的位置未知，不能开辟内存空间。（但可以作为函数形参，比如main（）函数就有char **argv参数）
*/











//python大法好
import re
s=re.split(r' ',input())
print(' '.join(s[::-1]))
