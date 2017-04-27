#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int M = 100003;
struct node{
    int parent,relation,num;
}person[M];


int finds(struct node x);
void unionset(int x,int y,int d);

int main()
{
    int N;scanf("%d",&N);
    int x,d;
    for(int i =1;i<=N;i++){
        person[i].num = i ;
        person[i].parent = i;
        person[i].relation = 0;
    }
    for(int i = 1;i<=N;i++){
        scanf("%d%d",&x,&d);
        if(finds(person[x]) != finds(person[i])){
            unionset(i,x,d);
        }
        else {
            if(d == 1) {
                if(person[i].relation != person[x].relation) {
                    printf("One face meng bi\n");
                    return 0;
                }
            }
            if(d == 2){
                if(person[x].relation == person[i].relation){
                    printf("One face meng bi\n");
                    return 0;
                }
            }
        }
    }
    printf("Time to show my power\n");
    return 0;
}

int finds(struct node x){
    if(x.num == x.parent) return x.num;
    int k = x.parent;
    x.parent = finds(person[x.parent]);
    x.relation = (person[k].relation+person[x.num].relation) % 2;
    return x.parent;
};
void unionset(int x,int y,int d){
    int a = finds(person[x]);
    int b = finds(person[y]);
    person[b].parent = a;
    person[b].relation = (person[y].relation + d - 1 + person[x].relation) % 2;
    person[y].parent = a;
    person[y].relation = (person[x].relation + d-1 )%2;
};
