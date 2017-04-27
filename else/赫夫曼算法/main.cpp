#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define maxhn 100000
#define inf 0x7fffffff//����һ���������

typedef struct {
    int weight;
    int parent,lchild,rchild;
    int weight1;
}hnode;/*������Huffman���Ľṹ������*/


void codehtree(hnode *h2,int y);/*���huffman����*/
void select(hnode *h1,int x,int j);/*�����ڽ������Ŷ�������Ӧ����*/
void sethtree(hnode *h1,int x);/*�������Ŷ������ĺ���*/

hnode huff1[maxhn];

int main()
{

    int total=0;
    printf("������������Ľ������");
    scanf("%d",&total);/*����������Ԫ�ĸ���*/
    sethtree(huff1,total);/*����Huffman��*/
    codehtree(huff1,total);/*�õ�Huffman���룬�����*/
    return 0;
}
void select(hnode *h1,int x,int j) /*�����ڽ������Ŷ�������Ӧ����*/
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
     }/*ѡȡ��ǰȨֵ��С��������*/
      h1[x+j].weight=h1[s1].weight+h1[s2].weight;
      h1[x+j].lchild=s1;
      h1[x+j].rchild=s2;
      h1[s1].parent=x+j;
      h1[s2].parent=x+j;/*��ɶ��½�㸳ֵ*/
      h1[s1].weight=inf;
      h1[s2].weight=inf;/*ÿһ�ν���ǰ��Сֵ���Сֵ�ڵ��Ϊ�����*/
};

void sethtree(hnode *h1,int x){/*�������Ŷ������ĺ���*/
     int i,j;
     for (i=0; i<2*x-1; i++)
    {
        h1[i].weight = 0;
        h1[i].parent =-1;
        h1[i].lchild =-1;
        h1[i].rchild =-1;
    }/*��ʼ��hnode����*/
    printf("������ÿ���������Ľ���Ȩֵ");
    for(i=0;i<x;i++){scanf("%d",&h1[i].weight); h1[i].weight1=h1[i].weight;}/*��������*/
    for(j=0;j<x-1;j++){select(h1,x,j);}/*����select������ɽ���������*/
};

void codehtree(hnode *h2,int y)/*���huffman����*/
{
    int j,k;
    char wei[100];//����һ������������������
    wei[99]='\0';
    for(int i=0;i<y;i++){
        k=98;
        j=i;
        while(h2[j].parent!=-1){
            if(h2[h2[j].parent].lchild==j) wei[k--]='0';
            else wei[k--]='1';
            j=h2[j].parent;
        }
     printf("ȨֵΪ%d����Ӧ�ĺշ�������Ϊ%s\n",h2[i].weight1,wei+k+1);
    }/*����Huffman���𼶱������õ��ڵ��Huffman���룬������hcode�����wei����*/
};
