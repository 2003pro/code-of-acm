#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define MAX 100
#define inf 0x7fffffff//����һ���������

struct node{
    int low;
    int adj;
};//����һ������¼����adj��һ���������low�Ľṹ��
node h1[MAX];

void prim(int h[][100],int x,int y);

int main()
{
    int graph[MAX][MAX];
    int i,j,k,m,n,weight;
    printf("�����������ͱ���");
    scanf("%d %d",&m,&n);//���������С��������ͼ���ڽӾ���
    memset(graph,0,sizeof(graph));//��ʼ���ڽӾ���
    printf("������ÿ�������ӵĽ��ͱ�Ȩֵ\n");
    for(k=0;k<n;k++){
        scanf("%d %d %d",&i,&j,&weight);
        graph[i][j]=weight;
        graph[j][i]=weight;
        }//����ÿ���ߵı�Ȩֵ,ע���ͼ������ͼ����Ҫ���ڽӾ���Գ�λ���ϵĵ㶼��ֵ
    prim(graph,m,n);//���prim�㷨�������С�������еı�
    return 0;
}

void prim(int h[][100],int x,int y){
            h1[0].adj=0;
            int i;
            for(i=0;i<x;i++){
                h1[i].low=h[0][i];
                if(h[0][i]==0) h1[i].low=inf;
                h1[i].adj=0;
            }//����¼����adj�;�������low����ֵ
            int t=0;
            printf("��С�������ı߰�����");
            for(i=1;i<x;i++){
                for(int j=0;j<x-1;j++){
                    if(h1[t].low>h1[j+1].low) t=j+1;
                }//�ҳ���С�������ı�
                h1[t].low=inf;//�����ظ����ʽڵ�
                printf("v%d--v%d  ",h1[t].adj,t);//�����С�������ı�
                for(int k=0;k<x;k++){
                   if(h1[k].low>h[t][k]&&h[t][k]!=0){
                        h1[k].low=h[t][k];
                        h1[k].adj=t;
                        h[k][t]=0;
                    }
                }//���¾������飬���������ͼ
            }
}

