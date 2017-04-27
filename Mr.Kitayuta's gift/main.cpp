#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
bool isPlain(string str);

int main()
{
    string str,d;
    int i,a;
    char j;
    bool c;
    while(cin>>str){
        c=false;
        a=str.size();
        for(i=0;i<=a;i++){
            for(j='a';j<='z';j++){
                d=str;
                string b;
                b=j;
                d.insert(i,b);
                if(isPlain(d)) {c=true;cout<<d<<endl;break;}
            }
            if(c) break;
        }
        if(!c){printf("NA\n");}
    }
    return 0;
}
bool isPlain(string str){
    string str1;
    str1=str;
    reverse(str1.begin(),str1.end());
    return str==str1;
}
