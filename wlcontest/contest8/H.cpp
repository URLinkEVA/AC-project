#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef basic_string<int> BI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

int START=0,ANS=1,L0=2,L1=3,ZERO=4,ONE=5,NEGONE=6;
int num=7,op=102;
int TMP=num++;
int SGN=num++;
int shit=1023;
int INPUT=100,PRINT=101;
unsigned int a[1030];
void setval(int x,unsigned int v) {
	a[x]=v;
}
void setprint(int x,int b) {
	a[x]=(b<<20);
}
void setinput(int x,int b,int c,int d) {
	a[shit]=c; a[shit-1]=d;
	a[x]=(1u<<30)+(b<<20)+(shit<<10)+shit-1;
	shit-=2;
}
void setadd(int x,int b,int c,int d) {
	a[shit]=d;
	a[x]=(2u<<30)+(b<<20)+(c<<10)+shit;
	--shit;
}
void setcond(int x,int b,int c,int d) {
	a[shit]=c; a[shit-1]=d;
	a[x]=(3u<<30)+(b<<20)+(shit<<10)+shit-1;
	shit-=2;
}

unsigned int r[1030];
void simulate(string s) {
	int pt=0,st=0;
	rep(i,0,1024) r[i]=a[i];
	while (1) {
		st++;
		int pc=r[0]%1024;
		int a=r[pc]>>30,b=(r[pc]>>20)%1024,c=(r[pc]>>10)%1024,d=r[pc]%1024;
		printf("%d %d %d %d %d %d\n",st,pc,a,b,c,d);
		printf("ANS : %u L0 : %u L1 : %u SGN : %u TMP : %u\n",r[ANS],r[L0],r[L1],r[SGN],r[TMP]);
		if (a==0) {
			printf("%u\n",r[b]);
			return;
		} else if (a==1) {
			if (pt==SZ(s)) r[0]=r[d];
			else r[b]=s[pt++],r[0]=r[c];
		} else if (a==2) r[b]+=r[c],r[0]=r[d];
		else {
			if (r[b]==0) r[0]=r[c];
			else r[0]=r[d];
		}
	}
}

int main() {
	setval(L0,1); setval(ONE,1); setval(NEGONE,-1);
	setval(START,INPUT);
	int CHECK1=op++;
	int CHECK12=op++;
	int CHECK2=op++;
	int CHECK22=op++;
	int CHECK3=op++;
	int CHECK32=op++;
	int CHECK4=op++;
	int DEALADD=op++;
	int DEALMIN=op++;
	int DEALMUL=op++;
	int DEALNUM=op++;

	int V1=num++,V2=num++,V3=num++,V4=num++;
	setval(V1,-('+'));
	setval(V2,'+'-'-');
	setval(V3,'-'-'*');
	setval(V4,'*'-'0');

	setinput(INPUT,SGN,CHECK1,PRINT);
	setadd(CHECK1,SGN,V1,CHECK12);
	setcond(CHECK12,SGN,DEALADD,CHECK2);
	setadd(CHECK2,SGN,V2,CHECK22);
	setcond(CHECK22,SGN,DEALMIN,CHECK3);
	setadd(CHECK3,SGN,V3,CHECK32);
	setcond(CHECK32,SGN,DEALMUL,CHECK4);
	setadd(CHECK4,SGN,V4,DEALNUM);
	setadd(DEALADD,ANS,L1,op);
	rep(i,0,32) setadd(op+i,L0,L0,op+i+1);
	op+=32;
	rep(i,0,32) setadd(op+i,L1,L1,op+i+1);
	op+=32;
	setadd(op++,L0,ONE,INPUT);

	setadd(DEALMIN,ANS,L1,op);
	rep(i,0,32) setadd(op+i,L0,L0,op+i+1);
	op+=32;
	rep(i,0,32) setadd(op+i,L1,L1,op+i+1);
	op+=32;
	setadd(op++,L0,NEGONE,INPUT);

	setadd(DEALMUL,ZERO,ZERO,op);
	rep(i,0,32) setadd(op+i,L0,L0,op+i+1);
	op+=32;
	setadd(op,L0,L1,op+1); op++;
	rep(i,0,32) setadd(op+i,L1,L1,op+i+1);
	op+=32;
	setadd(op++,ZERO,ZERO,INPUT);

	setadd(DEALNUM,ZERO,ZERO,op);
	rep(i,0,32) setadd(op+i,TMP,TMP,op+i+1);
	op+=32;
	setadd(op,TMP,L1,op+1); op+=1;
	rep(i,0,9) setadd(op,L1,TMP,op+1),op+=1;
	int NUMA=op++;
	setcond(NUMA,SGN,INPUT,op);
	setadd(op,L1,L0,op+1);
	setadd(op+1,SGN,NEGONE,NUMA);
	op+=2;
	setadd(PRINT,ANS,L1,op);
	setprint(op,ANS);
	rep(i,0,1024) printf("%u\n",a[i]);
	//simulate("114+514*123-191*12*3+123*999");
}
