#include <bits/stdc++.h>

using namespace std;
string sa[11],sc[9],sas[9];
map<string,int> mp;
void init(){
    sa[0] = "xxxxxx...xx...xx...xx...xx...xxxxxx";
    sa[1] = "....x....x....x....x....x....x....x";
    sa[2] = "xxxxx....x....xxxxxxx....x....xxxxx";
    sa[3] = "xxxxx....x....xxxxxx....x....xxxxxx";
    sa[4] = "x...xx...xx...xxxxxx....x....x....x";
    sa[5] = "xxxxxx....x....xxxxx....x....xxxxxx";
    sa[6] = "xxxxxx....x....xxxxxx...xx...xxxxxx";
    sa[7] = "xxxxx....x....x....x....x....x....x";
    sa[8] = "xxxxxx...xx...xxxxxxx...xx...xxxxxx";
    sa[9] = "xxxxxx...xx...xxxxxx....x....xxxxxx";
    sa[10] =".......x....x..xxxxx..x....x.......";
    for(int i = 0;i < 11;i++) mp[sa[i]] = i;
//    for(int l = 0;l < 11;l++){
//        for(int i = 0;i < 7;i++){
//            for(int j = 0;j < 5;j++)
//                printf("%c",nums[l].sa[i][j]);
//            printf("\n");
//        }
//        printf("\n");
//    }
}
int convert(int len){
    int k = 0,sl[4],l = 0;string ss;
    sl[0] = 0;sl[1] = 0;
    while(k + 5 < len){
        ss = "";
        for(int i = 0;i < 7;i++){
            ss += sc[i].substr(k,5);
        }
        if(mp[ss] != 10)sl[l] = sl[l]*10 + mp[ss];
        else l++;
        k += 6;
    }
    int ans = sl[0] + sl[1];
    return ans;
}
void print(int ans){
    int k = 0,ana[15],an = ans;
    while(an !=  0) k++,an /= 10 ;
    an = ans;
    for(int i = 0;i < k;i++) {ana[i] = an % 10;an /= 10;}
    int l;
    for(int i = k-1;i > 0;i--){
        l = 0;
        for(int j = 0;j < 7;j++){
            sas[j] += sa[ana[i]].substr(l,5);
            sas[j] += '.';
            l += 5;
        }
    }
    l = 0;
    for(int j = 0;j < 7;j++){
        sas[j] += sa[ana[0]].substr(l,5);
        l += 5;
    }
    for(int i = 0;i < 7;i++) cout<<sas[i]<<endl;
}
int main()
{
    init();
    for(int i = 0;i < 7;i++) {cin>>sc[i];sc[i]+='.';}
    //for(int i = 0;i < 7;i++) cout<<sc[i]<<endl;
    int len = sc[0].length();
    int ans = convert(len);
//    for (int i = 0; i < 10; i++) {
//        cout << sa[i] << endl;
//    }
//    printf("%d\n",ans);
    print(ans);
    return 0;
}
