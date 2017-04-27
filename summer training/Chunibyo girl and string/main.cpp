#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef struct TrieNode{
    int nCount;
    struct TrieNode *next[MAX];
} TrieNode;

TrieNode Memory[1000000];
int allocp = 0;

//初始化一个节点。nCount计数为1， next都为null
TrieNode * createTrieNode(){
    TrieNode * tmp = &Memory[allocp++];
    tmp->nCount = 1;
    for (int i = 0; i < MAX; i++) tmp->next[i] = NULL;
    return tmp;
}

void insertTrie(TrieNode * * pRoot, char * str){
    TrieNode * tmp = *pRoot;
    int i = 0, k;
    //一个一个的插入字符
    while (str[i]){
        k = str[i] - 'a'; //当前字符 应该插入的位置
        if (tmp->next[k])  {
            tmp->next[k]->nCount++;
        }
        else{
            tmp->next[k] = createTrieNode();
        }
        tmp = tmp->next[k];
        i++; //移到下一个字符
    }
}
int searchTrie(TrieNode * root, char * str){
    if (root == NULL) return 0;
    TrieNode * tmp = root;
    int i = 0, k;
    while (str[i]){
        k = str[i] - 'a';
        if (tmp->next[k]){
            tmp = tmp->next[k];
        }
        else  return 0;
        i++;
    }
    return tmp->nCount; //返回最后的那个字符  所在节点的 nCount
}


int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%s",&a);
        scanf("%s",&b);
        scanf("%d",&K);
        int tot = 0,sum = 0;
        tree *Trie = treeCreate();
        char word[N];
        for(int i = n - 1,j = n - 1;i > 0;i--){
            tot++;
            if(b[a[i] - 'a'] == '0') tot++;
            while(tot < K){
                if(b[a[--j] - 'a'] == '0') {
                    tot++;
                    strncpy(word,a[j],i - j + 1);
                    if(treeInsert(Trie,a[j],i - j + 1)) sum++;
                }
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
