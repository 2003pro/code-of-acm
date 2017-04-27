#include <iostream>
#include <cstdio>
#include <cstring>


const int N = 100009;
char a[N],b[N];
int next[N];

int makeNext(){
    int i = -1,j = 0;
    int nest[N];
    next[0] = -1;
    int l = strlen(b);
    while(j < l - 1){
        if(i == -1 || b[i] == b[j]){
            i++;
            j++;
            next[j] = i;
        }
        else i = next[i];
    }
}

int kmp(){
    int i = 0,j = 0;
    int sum = 0;
    int n = strlen(a);
    int m = strlen(b);
    while(i < n&&j < m){
        if(j == -1 || a[i] == b[j]){
            i++;
            j++;
        }
        else j = next[j];
        if(j == m) {
            sum++;
            j = 0;
        }
    }
    return sum;
}

int main()
{
    scanf("%s",&a);
    scanf("%s",&b);
    makeNext();
    int s = kmp();
    printf("%d\n",s);
    return 0;
}
