#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int base = 10000;

struct BigInt{
	int c[1000], len, sign;
	BigInt() { memset(c, 0, sizeof(c)); len = 1; sign = 0;}
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
		char s[1000] = {0};
		sprintf(s, "%d", a);
		writein(s);
		return *this;
	}
	bool operator == (const BigInt &b)
	{
		if(len != b.len) return 0;
		for(int i = 1; i <= len; i++)
			if(c[i] != b.c[i]) return 0;
		return 1;
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
};

int main()
{
	struct BigInt ss[3];
	ss[1].Zero(),ss[2].Zero();
	bool flag = false;
	ss[0].Read();ss[0].Zero();
	ss[1].Read();ss[1].Zero();
	ss[2].Read();ss[2].Zero();
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            struct BigInt t = ss[i] + ss[j];
            for(int k = 0;k < 3;k++) if(t == ss[k]) flag = true;
        }
    }
    if(flag) printf("YES\n");
    else printf("NO\n");
	return 0;
}
