#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#define MAX 100

struct  node{
     int  weight;
     int  vex;   //������
     struct  node  *next;   //����
};

struct tnode{
     int  in;  //�����
     struct   node  *link;    //����
};
tnode td[MAX];//����������ͷ���
tnode td1[MAX];//������������ͷ���

int m,n,k;
int ve[MAX],vl[MAX],e,l;//�������ڼ���ؼ�·��������ͱ���

using namespace std;
stack<int> s;

void creategraph();//����ͼ���洢���ڽӱ���
int topoorder();//�����������ve����
int topoorder1();//�������������vl����
void findpath();//�����ڽӱ��ve��vl����Ѱ�ҹؼ�·��

int main()
{
    printf("�����������ͱ���");
    scanf("%d %d",&m,&n);//��������m�Լ�����n
    creategraph();
    findpath();
    return 0;
}

void creategraph(){
    int i,j,w;
    printf("������ÿ�������ӵĽ��ͱ�Ȩֵ\n");
    for(int k=0;k<n;k++){
        scanf("%d %d %d",&i,&j,&w);
        td[j].in++;
        node *jd=new node;
        jd->vex=j;
        jd->next=td[i].link;
        td[i].link=jd;
        jd->weight=w;//���������������ڽӱ�
        td1[i].in++;
        node *jd1=new node;
        jd1->vex=i;
        jd1->next=td1[j].link;
        td1[j].link=jd1;
        jd1->weight=w;//�����������������ڽӱ�
    }//�����ڽӱ�
}

int topoorder(){
    memset(ve,0,sizeof(ve));//��ʼ��ve����
    int count1=0;//��¼ѭ�������ı����������ж�ͼ���Ƿ��л�
    int i;
    for(i=0;i<m;i++){
        if(td[i].in==0) s.push(i);
    }//��ջ�м����ʼֵ
    while(!s.empty()) {
            i = s.top();
            s.pop();
            count1++;
            for(node *p=td[i].link;p;p=p->next){
                td[p->vex].in--;
                k = p->vex;
                if(!(td[p->vex].in))  s.push(p->vex);
                if(ve[i]+(p->weight)>ve[k])  {ve[k] = ve[i]+(p->weight);}//������������������������������ve����
            }
    }
    if(count1<m) {printf("��ͼ���л������������޻�ͼ���޷���ؼ�·��"); return 0;}
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
    if(count1<m) {printf("��ͼ���л������������޻�ͼ���޷���ؼ�·��"); return 0;}
    return 1;
}

void findpath(){
    int i;
    if ((!topoorder())||(!topoorder1())) return ;//���������������ж������ͼ�Ƿ�Ϊ�����޻�ͼ
    printf("�ؼ�·���������ı��У�");
    for(i=0;i<m;i++){
    for(node  *p = td[i].link;p;p=p->next) {
        int k = p->vex;
        e = ve[i] ;
        l = vl[k]-p->weight;
        if(e==l)  printf("v%d--v%d  ",i,k);
        }//����ve��vl����õ�e��l��ֵ���ҳ��ؼ�·��
    }
}

