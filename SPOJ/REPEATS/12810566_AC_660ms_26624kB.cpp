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
const int maxn = 1e5+11;
const int oo = 0x3f3f3f3f;
const double eps = 1e-7;
typedef long long ll;
ll read(){
    ll x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
char str[maxn];int n;
struct SA{
    int Rank[maxn],sa[maxn],tsa[maxn],A[maxn],B[maxn];
    int cntA[maxn],cntB[maxn];
    int height[maxn],best[maxn][22],n; 
    void get(int nn){
        n=nn; 
        rep(i,0,666) cntA[i]=0;
        rep(i,1,n) cntA[str[i]]++;
        rep(i,1,666) cntA[i]+=cntA[i-1];
        rrep(i,n,1) sa[cntA[str[i]]--]=i;
        Rank[sa[1]]=1;
        rep(i,2,n){
            if(str[sa[i]]==str[sa[i-1]]){
                Rank[sa[i]]=Rank[sa[i-1]];
            }else{
                Rank[sa[i]]=1+Rank[sa[i-1]];
            }
        }
        for(int l=1;Rank[sa[n]]<n;l<<=1){
            rep(i,1,n) cntA[i]=cntB[i]=0;
            rep(i,1,n) cntA[A[i]=Rank[i]]++;
            rep(i,1,n) cntB[B[i]=(i+l<=n?Rank[i+l]:0)]++;
            rep(i,1,n) cntA[i]+=cntA[i-1],cntB[i]+=cntB[i-1];
            rrep(i,n,1) tsa[cntB[B[i]]--]=i;
            rrep(i,n,1) sa[cntA[A[tsa[i]]]--]=tsa[i];
            Rank[sa[1]]=1;
            rep(i,2,n){
                bool flag=A[sa[i]]==A[sa[i-1]]&&B[sa[i]]==B[sa[i-1]];
                flag=!flag;
                Rank[sa[i]]=Rank[sa[i-1]]+flag;
            }
        }
    }
    void ht(){
        int j=0;
        rep(i,1,n){
            if(j) j--;
            while(str[i+j]==str[sa[Rank[i]-1]+j]) j++;
            height[Rank[i]]=j;
        }
    }
    void rmq(){
        rep(i,1,n) best[i][0]=height[i];
        for(int i=1;(1<<i)<=n;i++){
            for(int j=1;j+(1<<i)-1<=n;j++){
                best[j][i]=min(best[j][i-1],best[j+(1<<(i-1))][i-1]);
            }
        }
    }
    int lcp(int l,int r){
        if(l==r)return -oo;
        if(l>r)swap(l,r);
        l++;
        int k=log(1.0*r-l+1)/log(2.0);
        return min(best[l][k],best[r-(1<<k)+1][k]);
    }
}sa;
int main(){
	int kase=0,T=read();
    while(T--){
        n=read();
        char tt[66];
        rep(i,1,n){
        	s1(tt);
        	str[i]=tt[1];
		}
        sa.get(n);
        sa.ht();
        sa.rmq();
        int ans=1;
        for(int L=1;L<=n;L++){//L!=2 
        	for(int i=1;i+L<=n;i+=L){
        		int K=sa.lcp(sa.Rank[i],sa.Rank[i+L]);
        		int t=K/L+1;
        		int pos=i-(L-K%L);
        		if(pos>=1&&sa.lcp(sa.Rank[pos],sa.Rank[pos+L])/L+1>t)t++;
        		ans=max(ans,t);
			}
		}
		println(ans);
    }
    return 0;
}