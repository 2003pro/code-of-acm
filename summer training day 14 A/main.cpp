#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;
const int base = 10000; // ѹ4λ
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
	BigInt operator / (BigInt b)//����
	{
		BigInt t, r;
		if(b == 0) return r;
		r.len = len;
		for(int i = len; i >= 1; i--)
		{
			t = t * base + c[i];
			int div;
			//------try------
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
			//------end------
			r.c[i] = div;
			t = t - b * div;
		}
		//����tΪ������Ҫ�õ��Լ���취����ȥ
		r.Zero();
		return r;
	}
	BigInt operator / (const int &a)
	{
		BigInt b; b = a;
		return *this / b;
	}
	BigInt operator % (const BigInt &b)
	{//��ʵ���Ը�����������ģ����ﻻһ��д��
		return *this - *this / b * b;
	}
	BigInt operator % (const int &a)
	{
		BigInt b; b = a;
		return *this % b;
	}
};
void solve(int x){
    struct BigInt a[203];int l = x;
    if(x%2 == 1){
        a[1] = 1,a[1].Zero();
        a[2] = 2,a[2].Zero();
        a[3] = 3,a[3].Zero();
        x -= 3;int cnt = 4;
        while(x > 0){
            a[cnt] = a[cnt-2]*6,a[cnt].Zero();
            a[cnt+1] = a[cnt-1]*6,a[cnt+1].Zero();
            cnt += 2;x -= 2;
            if(a[cnt-1].len > 26) {printf("-1\n");return ;}
        }
        for(int i = 1;i <= l;i++) a[i].Print();
    }
    else{
        if(x == 4) printf("1\n2\n6\n9\n");
        else{
            x -= 3;struct BigInt a1,a2,a3;
            a1 = 12,a1.Zero();a2 = 36,a2.Zero();a3 = 54,a3.Zero();
            a[1] = 1,a[1].Zero();
            a[2] = 2,a[2].Zero();
            a[3] = 3,a[3].Zero();
            x -= 3;int cnt = 4;
            while(x > 0){
                a[cnt] = a[cnt-2]*6,a[cnt].Zero();
                a[cnt+1] = a[cnt-1]*6,a[cnt+1].Zero();
                cnt += 2;x -= 2;a1 = a1*6,a2 = a2*6,a3 = a3*6;
                if(a[cnt-1].len > 26 || a1.len > 26 || a2.len > 26 || a3.len > 26) {printf("-1\n");return ;}
            }
            for(int i = 1;i <= l - 3;i++) a[i].Print();
            a1.Print();a2.Print();a3.Print();
        }
    }
}
int main()
{
    int T;scanf("%d",&T);
    while(T--){
        int x;
        scanf("%d",&x);
        if(x > 2)solve(x);
        else printf("-1\n");
    }
    return 0;
}