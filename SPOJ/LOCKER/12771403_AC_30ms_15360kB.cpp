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
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
ll fpw(ll a,ll n,ll mod){
	ll ans=1;
	while(n){
		if(n&1) ans=(ans*a)%mod;
		n>>=1;
		a=(a*a)%mod;
	}
	return ans;
}
int main(){
	int T=read();
	const int mod = 1e9+7;
	while(T--){
		ll n=read();
		ll ans=0;
		if(n%3==0){
			ans=fpw(3,n/3,mod);
		}else if(n%3==1){
			if(n==1)ans=1;
			else ans=max(fpw(3,n/3-1,mod)*4,fpw(3,n/3,mod));//3 1 -> 2 2
		}else{
			if(n==2)ans=2;
			else ans=fpw(3,n/3,mod)*2;//3 2
		}
		println((ans%mod));
	}
	return 0;
}
