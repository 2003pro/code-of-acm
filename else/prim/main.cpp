#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define MAX 100
#define inf 0x7fffffff//定义一个无穷大量

struct node{
    int low;
    int adj;
};//定义一个含记录变量adj和一个距离变量low的结构体
node h1[MAX];

void prim(int h[][100],int x,int y);

int main()
{
    int graph[MAX][MAX];
    int i,j,k,m,n,weight;
    printf("请输入结点数和边数");
    scanf("%d %d",&m,&n);//输入待求最小生成树的图的邻接矩阵
    memset(graph,0,sizeof(graph));//初始化邻接矩阵
    printf("请输入每条边连接的结点和边权值\n");
    for(k=0;k<n;k++){
        scanf("%d %d %d",&i,&j,&weight);
        graph[i][j]=weight;
        graph[j][i]=weight;
        }//读入每条边的边权值,注意此图是无向图，故要对邻接矩阵对称位置上的点都赋值
    prim(graph,m,n);//完成prim算法并输出最小生成树中的边
    return 0;
}

void prim(int h[][100],int x,int y){
            h1[0].adj=0;
            int i;
            for(i=0;i<x;i++){
                h1[i].low=h[0][i];
                if(h[0][i]==0) h1[i].low=inf;
                h1[i].adj=0;
            }//给记录数组adj和距离数组low赋初值
            int t=0;
            printf("最小生成树的边包含：");
            for(i=1;i<x;i++){
                for(int j=0;j<x-1;j++){
                    if(h1[t].low>h1[j+1].low) t=j+1;
                }//找出最小生成树的边
                h1[t].low=inf;//避免重复访问节点
                printf("v%d--v%d  ",h1[t].adj,t);//输出最小生成树的边
                for(int k=0;k<x;k++){
                   if(h1[k].low>h[t][k]&&h[t][k]!=0){
                        h1[k].low=h[t][k];
                        h1[k].adj=t;
                        h[k][t]=0;
                    }
                }//更新距离数组，距离数组和图
            }
}

