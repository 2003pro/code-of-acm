#include <bits/stdc++.h>
using namespace std;
const int maxn = 4 + 5;
const int inf = 1e9 + 1e8;
int gcd(int x ,int y){
	return y ? gcd( y , x % y ) : x;
}

struct data{
	int up , down;
	data(int up = 0 , int down = 1) : up(up) ,down(down){}
	friend data operator + (const data & X,const data & Y){
		int A = X.up , B = X.down , C = Y.up , D = Y.down;
		int newup = A*D + B*C;
		int newdown = B*D;
		if(newdown==0) newdown=1;
		int gc = gcd( newup , newdown );
		return data(newup / gc , newdown / gc);
	}
	friend data operator * (const data & x, const data & y){
		int A = x.up , B = x.down , C = y.up , D = y.down;
		int newup = A*C;
		int newdown = B*D;
		if(newdown==0) newdown=1;
		int gc = gcd( newup , newdown );
		return data(newup / gc , newdown / gc);
	}
	friend data operator - (const data & x , const data & y){
		int A = x.up , B = x.down , C = y.up , D = y.down;
		int newup = A*D - B*C;
		int newdown = B*D;
		if(newdown==0) newdown=1;
		int gc = gcd( newup , newdown );
		return data(newup / gc , newdown / gc);
	}
	friend data operator / (const data & x , const data & y){
		int A = x.up , B = x.down , C = y.up , D = y.down;
		int newup = A*D;
		int newdown = B*C;
		if(newdown==0) newdown=1;
		int gc = gcd( newup , newdown );
		return data(newup / gc , newdown / gc);
	}
};

data arr[maxn];
vector < int > str;
char oper[4];
bool ok;
int vis[50];

vector < data > ss;

data calf(vector<data>&gg){
	ss.clear();
	/*cout <<"sz is " << gg.size() << endl;
					for(int i = 0 ; i < gg.size() ; ++ i){
					int upv = gg[i].up;
					if(upv>=inf) cout << (char)(upv-inf);
					else cout << (double)(upv) / (double)gg[i].down;
				}cout << endl;*/
	for(int i = 0 ; i < gg.size() ; ++ i){
		int c = gg[i].up;
		if(c >= inf){
			c-=inf;
			if(c=='+'||c=='-') ss.push_back(data(c+inf,1));
			else{
				data pre = ss.back();ss.pop_back();
				data fs = gg[++i];
				if(c=='/') ss.push_back(pre/fs);
				else ss.push_back(pre*fs);
			}
		}else{
			ss.push_back(gg[i]);
		}
	}
	data ans = data(0,1);
	int bg = 0 ;
	if(ss[0].up < inf) bg = 1 , ans = ss[0];
	for(int i = bg ; i < ss.size() ; i += 2){
		int c = ss[i].up;
		data sb = ss[i+1];
		c-=inf;
		if(c=='+') ans = ans + sb;
		else ans = ans - sb;
	}
	return ans;
}

void caculate(){
	int sz = str.size();
	vector < data > all;
	for(int i = 0 ; i < sz ; ++ i){
		int j ;
		vector < data > cal;
		cal.clear();
		for(j = i + 1 ; j < sz ; ++ j){
			if(str[j]==')') break;
			else if(str[j] <= 4 && str[j] >= 0){
				cal.push_back(arr[str[j]]);
			}
			else{
				cal.push_back(data(str[j]+inf,1));
			}
		}
		j++;
		data ans = calf(cal);
		//cout <<ans.up << " " <<ans.down << endl;
		//exit(0);
		all.push_back(ans);
		if(j < sz){
			all.push_back(str[j]+inf);
		}
		i = j;
	}
/*cout << "sz is " << all.size() << endl;
	cout << "run here" << endl;
				for(int i = 0 ; i < all.size() ; ++ i){
					int upv = all[i].up;
					if(upv>=inf) cout << (char)(upv-inf);
					else cout << (double)(upv) / (double)all[i].down;
				}cout << endl;
				exit(0);*/
	data res = calf(all);
	if(res.up == 24 && res.down == 1) ok = true;
}

void dfs(int cur){
	if(ok) return;
	if(cur==4){
		str.push_back(')');
		/*cout <<"caulate expression is ";
		for(int i = 0 ; i < str.size() ; ++ i){
			if(str[i]<=4) cout << (char)(str[i]+'0');
			else cout << (char)str[i];
		}
		cout <<"Szie is " << str.size() << endl;*/
		caculate();
		str.pop_back();
		return;
	}
    int ed;
    if(cur==0) ed = 2;
    else ed = 4;
    if(cur==0) str.push_back('(');
    for(int op = 0 ; op < ed ; ++ op){
    	for(int i = 0 ; i < 4 ; ++ i){
	    	if(vis[i]) continue;
	    	str.push_back(oper[op]);
	    	str.push_back(i);
	    	vis[i] = 1;
	    	dfs(cur+1);
	    	str.pop_back();
	    	str.pop_back();
	    	vis[i] = 0;
        }
        if(cur){
        	str.push_back(')');
        	str.push_back(oper[op]);
        	str.push_back('(');
	    	for(int i = 0 ; i < 4 ; ++ i){
		    	if(vis[i]) continue;
		    	str.push_back(i);
		    	vis[i] = 1;
		    	dfs(cur + 1);
		    	str.pop_back();
		    	vis[i] = 0;
	        }
	        str.pop_back();
	    	str.pop_back();
	    	str.pop_back();
        }
    }
    if(cur==0) str.pop_back();
}

int main(int argc,char *argv[]){
	int Case ;
//	freopen("out.txt","w",stdout);
	oper[0] = '+' , oper[1] = '-' , oper[2] = '*' ,oper[3] = '/';
	cin >> Case;
	while(Case--){
		memset(vis,0,sizeof(vis));
		ok = false;
		str.clear();
		for(int i = 0 ; i < 4 ; ++ i){
			int val;
			cin >> val;
			arr[i].up = val;
		}
		dfs(0);
		if(ok) cout<<"yes"<<endl;
		else cout <<"no"<<endl;
	}
	return 0;
}
