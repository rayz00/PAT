给定一系列正整数，请按要求对数字进行分类，并输出以下5个数字：
A1 = 能被5整除的数字中所有偶数的和；
A2 = 将被5除后余1的数字按给出顺序进行交错求和，即计算n1-n2+n3-n4...；
A3 = 被5除后余2的数字的个数；
A4 = 被5除后余3的数字的平均数，精确到小数点后1位；
A5 = 被5除后余4的数字中最大数字。
输入格式：
每个输入包含1个测试用例。每个测试用例先给出一个不超过1000的正整数N，
随后给出N个不超过1000的待分类的正整数。数字间以空格分隔。
输出格式：
对给定的N个正整数，按题目要求计算A1~A5并在一行中顺序输出。
数字间以空格分隔，但行末不得有多余空格。
若其中某一类数字不存在，则在相应位置输出“N”。
输入样例1：
13 1 2 3 4 5 6 7 8 9 10 20 16 18
输出样例1：
30 11 2 9.7 9
输入样例2：
8 1 2 4 5 6 7 9 16
输出样例2：
N 11 2 N 9






//python
s=list(map(int,input().split()))
s.remove(s[0])
if len([i for i in s if i%2==0 and i%5==0])==0:
    A1='N'
else:
    A1 = sum([i for i in s if i % 2 == 0 and i % 5 == 0])
if len([i for i in s if i%5==1])==0:
    A2='N'
else:
    A2 = sum([i for i in s if i % 5 == 1][::2]) - sum([i for i in s if i % 5 == 1][1::2])
if len([i for i in s if i%5==2])==0:
    A3='N'
else:
    A3=len([i for i in s if i%5==2])
if len([i for i in s if i%5==3])==0:
    A4='N'
else:
    A4=round(sum([i for i in s if i%5==3])/float(len([i for i in s if i%5==3])),1)\
if len([i for i in s if i%5==4])==0:
    A5 = 'N'
else:
    A5=max([i for i in s if i%5==4])
print(' '.join(str(i) for i in [A1,A2,A3,A4,A5]))
