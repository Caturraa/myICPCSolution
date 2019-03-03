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
ll MOD;
inline ll mod(ll a){return a%MOD;}
struct Matrix{
    ll mt[77][77],r,c;
    void init(int rr,int cc,bool flag=0){
        r=rr;c=cc;
        memset(mt,0,sizeof mt);
        if(flag) rep(i,1,r) mt[i][i]=1;
    }
    Matrix operator * (const Matrix &rhs)const{
        Matrix ans; ans.init(r,rhs.c);
        rep(i,1,r){
            rep(j,1,rhs.c){
                int t=max(r,rhs.c);
                rep(k,1,t){
                    ans.mt[i][j]+=mod(mt[i][k]*rhs.mt[k][j]);
                    ans.mt[i][j]=mod(ans.mt[i][j]);
                }
            }
        }
        return ans;
    }
};
Matrix fpw(Matrix A,ll n){
    Matrix ans;ans.init(A.r,A.c,1);
    while(n){
        if(n&1) ans=ans*A;
        n>>=1;
        A=A*A;
    }
    return ans;
}
int main(){
	ll n,k,m;
	while(cin>>n>>k>>m){
		MOD=m;
		Matrix A; A.init(n,n);
		rep(i,1,n)rep(j,1,n) A.mt[i][j]=read();
		Matrix UNIT; UNIT.init(n,n,1);
		Matrix B; B.init(n<<1,n<<1);
		rep(i,1,n)rep(j,1,n) B.mt[i][j]=A.mt[i][j];
		rep(i,1,n)rep(j,n+1,n<<1) B.mt[i][j]=UNIT.mt[i][j-n];
		rep(i,n+1,n<<1)rep(j,n+1,n<<1) B.mt[i][j]=UNIT.mt[i-n][j-n];
		Matrix res=fpw(B,k+1);
		rep(i,1,n){
			rep(j,1,n){
				print(mod(res.mt[i][j+n]-(i==j)+m));
				if(j<n) blank;
				else enter;
			}
		}
	}
	return 0;
}