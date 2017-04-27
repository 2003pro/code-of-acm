#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;
typedef struct node{
    int w;
    struct node *next;
}Node;

int main()
{
    int T,a,b,i,m;
    Node *head,*p,*s,*t;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&a,&b);
        for(i=1;i<=a;i++){
            s=new Node;
            s->w=i;
            s->next=NULL;
            if(i==1){
                head=s;
                p=head;
            }
            else {
                p->next=s;
                p=p->next;
            }
        }
        p->next=head;
        s=head;
        m=0;
        do{
            m++;
            if(m==b-1){
                t=s->next;
                s->next=t->next;
                m=0;
                delete t;
            }
            s=s->next;

        }
        while(s->next!=s);
        printf("%d",s->w);
    }
    return 0;
}
