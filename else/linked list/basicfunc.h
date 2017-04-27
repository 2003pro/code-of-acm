#ifndef BASICFUNC_H_INCLUDED
#define BASICFUNC_H_INCLUDED

typedef struct _node
{
    int value;
    struct _node *next;
}Node;

typedef struct _list{
     Node* head;
}List;

void add(List* plist,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        //add to the linked-list
        Node *p=(Node*)malloc(sizeof(Node));
        scanf("%d",&p->value);
        p->next=NULL;
        Node *last=plist->head;
        if(last)
        {
            //find the list
            while(last->next)
            {
            last=last->next;
            }
            //attach
            last->next=p;
        }
        else plist->head=p;
    }
}

void print(List* plist)
{
    Node* p1;
    if(plist->head)
    {
    for(p1=plist->head;p1;p1=p1->next)
    {
        printf("%d\t",p1->value);
    }
    printf("\n");
    }
}

#endif // BASICFUNC_H_INCLUDED
