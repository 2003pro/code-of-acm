#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define maxhn 100000
#define inf 0x7fffffff//定义一个无穷大量

typedef struct {
    int weight;
    int parent,lchild,rchild;
    int weight1;
}hnode;/*定义存放Huffman树的结构体数组*/


void codehtree(hnode *h2,int y);/*输出huffman编码*/
void select(hnode *h1,int x,int j);/*用于在建立最优二叉树对应数组*/
void sethtree(hnode *h1,int x);/*建立最优二叉树的函数*/

hnode huff1[maxhn];

int main()
{

    int total=0;
    printf("请输入待求编码的结点数量");
    scanf("%d",&total);/*输入待求编码元的个数*/
    sethtree(huff1,total);/*建立Huffman树*/
    codehtree(huff1,total);/*得到Huffman编码，并输出*/
    return 0;
}
void select(hnode *h1,int x,int j) /*用于在建立最优二叉树对应数组*/
{
    int  s1,s2;
    if (h1[0].weight<h1[1].weight){
        s1=0;
        s2=1;
    }
    else {s1=1; s2=0;}
    for(int i=2;i<x+j;i++){
        if (h1[s1].weight>h1[i].weight){
                s2=s1;
                s1=i;
            }
         else if(h1[s2].weight>h1[i].weight)  s2=i;
     }/*选取当前权值最小的两个点*/
      h1[x+j].weight=h1[s1].weight+h1[s2].weight;
      h1[x+j].lchild=s1;
      h1[x+j].rchild=s2;
      h1[s1].parent=x+j;
      h1[s2].parent=x+j;/*完成对新结点赋值*/
      h1[s1].weight=inf;
      h1[s2].weight=inf;/*每一次将当前最小值与次小值节点变为无穷大*/
};

void sethtree(hnode *h1,int x){/*建立最优二叉树的函数*/
     int i,j;
     for (i=0; i<2*x-1; i++)
    {
        h1[i].weight = 0;
        h1[i].parent =-1;
        h1[i].lchild =-1;
        h1[i].rchild =-1;
    }/*初始化hnode数组*/
    printf("请输入每个待求编码的结点的权值");
    for(i=0;i<x;i++){scanf("%d",&h1[i].weight); h1[i].weight1=h1[i].weight;}/*输入数据*/
    for(j=0;j<x-1;j++){select(h1,x,j);}/*调用select函数完成建立最优树*/
};

void codehtree(hnode *h2,int y)/*输出huffman编码*/
{
    int j,k;
    char wei[100];//定义一个用于输出编码的数组
    wei[99]='\0';
    for(int i=0;i<y;i++){
        k=98;
        j=i;
        while(h2[j].parent!=-1){
            if(h2[h2[j].parent].lchild==j) wei[k--]='0';
            else wei[k--]='1';
            j=h2[j].parent;
        }
     printf("权值为%d结点对应的赫夫曼编码为%s\n",h2[i].weight1,wei+k+1);
    }/*沿着Huffman树逐级遍历，得到节点的Huffman编码，并存入hcode数组的wei部分*/
};
