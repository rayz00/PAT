#include <iostream>
#include <map>
#include <vector>
using namespace std;

map<int,vector<int>> tree;      //输入
vector<int> result;             //输出

int main() {                    //构造输入
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;++i){
        int p,k,s;
        cin>>p>>k;
        for(int j=0;j<k;++j){
            cin>>s;
            tree[p].push_back(s);
        }
    }
    vector<int> current;                 //2个序列表示当前和下一层级，非常有技巧。next是实际生成的每一层，current只是借用next的内容用来迭代
    vector<int> next={01};               //每次迭代后 next内容清空 重新生成新层级
    int index=0;                         //代表层级，while（next层非空）遍历所有层级
    while(!next.empty()){
        result.push_back(0);             //vector必须先添元素才可以访问和修改！！每一层先添加个0元素再修改
        swap(current,next);              //上一个循环生成的next就是当前循环的current
        next.clear();                    //清空next容器，准备重新添加元素
        for(auto ite=current.begin();ite!=current.end();++ite){
            if(tree[*ite].empty())++result[index];                                      //没有子女，计数+1
            for(auto j=tree[*ite].begin();j!=tree[*ite].end();++j)next.push_back(*j);   //有子女，把子女加到next列表
        }
        ++index;
    }
    cout<<result[0];
    for(int i=1;i<result.size();++i){
        cout<<" "<<result[i];
    }
}

难点1:用什么样的数据结构表示输入输出？map完美适合邻接链表，输出结果用vector。
难点2:层级循环，需要厘清实际的每一层（next）和用来迭代的层（current），next的内容要传给current，每次用完清空，所以用到swap和clear函数
    cout<<result[0];
