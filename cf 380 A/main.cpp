#include <bits/stdc++.h>

using namespace std;
string s,t;
int n;
int main()
{
    cin>>n>>s;
    for(int i = 0;i < n;i++){
        if(s[i] == 'o' && s[i+1] == 'g' && s[i+2] == 'o' && i+2 < n) {
            while(s[i+1] == 'g' && s[i+2] == 'o' && i+2 < n) i += 2;
            t += "***";
        }
        else t += s[i];
    }
    cout << t <<endl;
//    t += 'aa';
//    cout << t <<endl;
    return 0;
}
