#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define erep(i,u) for(register int i=head[u];~i;i=nxt[i])
#define iin(a) scanf("%d",&a)
#define lin(a) scanf("%lld",&a)
#define din(a) scanf("%lf",&a)
#define s0(a) scanf("%s",a)
#define s1(a) scanf("%s",a+1)
#define print(a) printf("%lld",(ll)a)
#define enter putchar('\n')
#define blank putchar(' ')
#define println(a) printf("%lld\n",(ll)a)
#define IOS ios::sync_with_stdio(0)
using namespace std;
const int maxn = 1e6+11;
const int oo = 0x3f3f3f3f;
const double eps = 1e-7;
typedef long long ll;
const ll mod = 10000007;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
ll fpw(ll a,ll n){
	ll ans=1;
	while(n){
		if(n&1) ans=(ans*a)%mod;
		n>>=1;
		a=(a*a)%mod;
	}
	return ans;
}
double jie[maxn];
int main(){
	rep(i,1,maxn-333)jie[i]=log2(i)+jie[i-1];
//	rep(i,1,maxn-333) cout<<i<<" "<<jie[i]<<endl; 
	int y;
	while(cin>>y){
		if(y==0)break;
		int bit=(y-1960)/10+2;//cout<<bit<<endl;
		double tmp=pow(2,bit);
		int pos=lower_bound(jie+1,jie+maxn-333,tmp)-jie;
		if(jie[pos]>tmp+eps);pos--;
		cout<<pos<<endl;
	}
	return 0;
}