#include <bits/stdc++.h>

using namespace std;
string s,t,s1,t1;
vector<char> v1,v2;
char a1[100003],a2[100003];
const int base = 10000; // ัน4ฮป

struct BigInt{
	int c[1000], len, sign;
	BigInt() { memset(c, 0, sizeof(c)); len = 1; sign = 0; }
	void Zero()
	{
		while(len > 1 && c[len] == 0) len--;
		if(len == 1 && c[len] == 0) sign = 0;
	}
	void writein(char *s)
	{
		int k = 1, L = strlen(s);
		for(int i = L-1; i >= 0; i--)
		{
			c[len] += (s[i]-'0') * k;
			k *= 10;
			if(k == base)
			{
				k = 1;
				len++;
			}
		}
	}
	void Read()
	{
		char s[5000] = {0};
		scanf("%s", s);
		writein(s);
	}
	void Print()
	{
		if(sign) printf("-");
		printf("%d", c[len]);
		for(int i = len-1; i >= 1; i--) printf("%04d", c[i]);
		printf("\n");
	}
	BigInt operator = (int a)
	{
		char s[100] = {0};
		sprintf(s, "%d", a);
		writein(s);
		return *this;
	}
	bool operator > (const BigInt &b)
	{
		if(len != b.len) return len > b.len;
		for(int i = len; i >= 1; i--)
		{
			if(c[i] != b.c[i]) return c[i] > b.c[i];
		}
		return 0;
	}
	bool operator < (const BigInt &b)
	{
		if(len != b.len) return len < b.len;
		for(int i = len; i >= 1; i--)
		{
			if(c[i] != b.c[i]) return c[i] < b.c[i];
		}
		return 0;
	}
	bool operator == (const BigInt &b)
	{
		if(len != b.len) return 0;
		for(int i = 1; i <= len; i++)
			if(c[i] != b.c[i]) return 0;
		return 1;
	}
	bool operator == (const int &a)
	{
		BigInt b; b = a;
		return *this == b;
	}
	BigInt operator + (const BigInt &b)
	{
		BigInt r; r.len = max(len, b.len) + 1;
		for(int i = 1; i <= r.len; i++)
		{
			r.c[i] += c[i] + b.c[i];
			r.c[i+1] += r.c[i] / base;
			r.c[i] %= base;
		}
		r.Zero();
		return r;
	}
	BigInt operator + (const int &a)
	{
		BigInt b; b = a;
		return *this + b;
	}
	BigInt operator - (const BigInt &b)
	{
		BigInt a, c;// a - c
		a = *this; c = b;
		if(a < c)
		{
			std::swap(a, c);
			a.sign = 1;
		}
		for(int i = 1; i <= a.len; i++)
		{
			a.c[i] -= c.c[i];
			if(a.c[i] < 0)
			{
				a.c[i] += base;
				a.c[i+1]--;
			}
		}
		a.Zero();
		return a;
	}
	BigInt operator - (const int &a)
	{
		BigInt b; b = a;
		return *this - b;
	}
	BigInt operator * (const BigInt &b)
	{
		BigInt r; r.len = len + b.len + 2;
		for(int i = 1; i <= len; i++)
		{
			for(int j = 1; j <= b.len; j++)
			{
				r.c[j+i-1] += c[i] * b.c[j];
			}
		}
		for(int i = 1; i <= r.len; i++)
		{
			r.c[i+1] += r.c[i] / base;
			r.c[i] %= base;
		}
		r.Zero();
		return r;
	}
	BigInt operator * (const int &a)
	{
		BigInt b; b = a;
		return *this * b;
	}
	BigInt operator / (BigInt b)//ี๛ณý
	{
		BigInt t, r;
		if(b == 0) return r;
		r.len = len;
		for(int i = len; i >= 1; i--)
		{
			t = t * base + c[i];
			int div;
				int up = 10000, down = 0;
				while(up >= down)
				{
					int mid = (up + down) / 2;
					BigInt ccc ; ccc = b * mid;
					if(ccc > t) up = mid - 1;
					else {
						down = mid + 1;
						div = mid;
					}
				}
			r.c[i] = div;
			t = t - b * div;
		}
		r.Zero();
		return r;
	}
	BigInt operator / (const int &a)
	{
		BigInt b; b = a;
		return *this / b;
	}
};
int main()
{
    cin>>s>>t;
    int l = s.length(),n = t.length();
    int sd = s.find('.'),td = t.find('.');
    if (sd == -1) sd = s.size();
    int shift = n - td - 1;
    if (td == -1) shift = 0;
    for(int i = 0;i < n;i++) {
        if(i == td) continue;
        v2.push_back(t[i]);
        //printf ("%c\n",t[i]);
    }
    int k = 0;
    while(v2[k] == '0') k++;
    int tt = 0;
    n = v2.size();
    for(int i = k;i < n;i++) {a2[tt] = v2[i];tt++;}
    if(sd != 0) {
        for(int i = 0;i < sd;i++) v1.push_back(s[i]);
    }
    int tm = 0;

    if (td != 0)
        for(int i = sd+1;tm < shift;i++,tm++) {
            if(i < l) v1.push_back(s[i]);
            else v1.push_back('0');
        }
    k = 0;
    while(v1[k] == '0') k++;
    tt = 0;l = v1.size();
    for(int i = k;i < l;i++) {a1[tt] = v1[i];tt++;}
//    puts(a1);
//    puts(a2);
    BigInt b1,b2,ans;
    b1.writein(a1),b2.writein(a2);
    b1.Zero(),b2.Zero();
    ans = b1/b2;
    ans.Zero();
    ans.Print();
    return 0;
}
