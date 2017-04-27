#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#define MAX 100

struct  node{
     int  weight;
     int  vex;   //顶点域
     struct  node  *next;   //链域
};

struct tnode{
     int  in;  //入度域
     struct   node  *link;    //链域
};
tnode td[MAX];//拓扑排序用头结点
tnode td1[MAX];//逆拓扑排序用头结点

int m,n,k;
int ve[MAX],vl[MAX],e,l;//定义用于计算关键路径的数组和变量

using namespace std;
stack<int> s;

void creategraph();//读入图并存储在邻接表中
int topoorder();//拓扑排序并求出ve数组
int topoorder1();//逆拓扑排序并求出vl数组
void findpath();//利用邻接表和ve，vl数组寻找关键路径

int main()
{
    printf("请输入结点数和边数");
    scanf("%d %d",&m,&n);//读入结点数m以及边数n
    creategraph();
    findpath();
    return 0;
}

void creategraph(){
    int i,j,w;
    printf("请输入每条边连接的结点和边权值\n");
    for(int k=0;k<n;k++){
        scanf("%d %d %d",&i,&j,&w);
        td[j].in++;
        node *jd=new node;
        jd->vex=j;
        jd->next=td[i].link;
        td[i].link=jd;
        jd->weight=w;//建立拓扑排序用邻接表
        td1[i].in++;
        node *jd1=new node;
        jd1->vex=i;
        jd1->next=td1[j].link;
        td1[j].link=jd1;
        jd1->weight=w;//建立逆拓扑排序用邻接表
    }//建立邻接表
}

int topoorder(){
    memset(ve,0,sizeof(ve));//初始化ve数组
    int count1=0;//记录循环次数的变量，用于判断图中是否有环
    int i;
    for(i=0;i<m;i++){
        if(td[i].in==0) s.push(i);
    }//往栈中加入初始值
    while(!s.empty()) {
            i = s.top();
            s.pop();
            count1++;
            for(node *p=td[i].link;p;p=p->next){
                td[p->vex].in--;
                k = p->vex;
                if(!(td[p->vex].in))  s.push(p->vex);
                if(ve[i]+(p->weight)>ve[k])  {ve[k] = ve[i]+(p->weight);}//完成拓扑排序并在拓扑排序过程中生成ve数组
            }
    }
    if(count1<m) {printf("该图中有环，不是有向无环图，无法求关键路径"); return 0;}
    return 1;
}

int topoorder1(){
    int count1=0;
    int i;
    for(i=0;i<m;i++){vl[i]=ve[m-1];}
    for(i=0;i<m;i++){
        if(td1[i].in==0) s.push(i);
    }
    while(!s.empty()) {
            i = s.top();
            s.pop();
            count1++;
            for(node *p=td1[i].link;p;p=p->next){
                td1[p->vex].in--;
                k = p->vex;
                if(!(td1[p->vex].in))  s.push(p->vex);
                if(vl[i]-(p->weight)<vl[k])  vl[k] = vl[i]-(p->weight);
            }
    }
    if(count1<m) {printf("该图中有环，不是有向无环图，无法求关键路径"); return 0;}
    return 1;
}

void findpath(){
    int i;
    if ((!topoorder())||(!topoorder1())) return ;//依据拓扑排序结果判定读入的图是否为有向无环图
    printf("关键路径所包含的边有：");
    for(i=0;i<m;i++){
    for(node  *p = td[i].link;p;p=p->next) {
        int k = p->vex;
        e = ve[i] ;
        l = vl[k]-p->weight;
        if(e==l)  printf("v%d--v%d  ",i,k);
        }//依据ve和vl数组得到e和l的值，找出关键路径
    }
}

