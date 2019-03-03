#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#define rep(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
const int maxn = 1e4+11;
typedef pair<int,int> P;
bool rev[maxn];//rev[i]:[i..i+k-1]
bool dir[maxn];
char str[6];
int n,sum[maxn];
int check(int i,int k){
    if(k>=2){
        if(i+1-k>0) return sum[i-1]-sum[i-k];
        else  return sum[i-1];
    }else{
        return 0;
    }
}
int main(){
    ios::sync_with_stdio(0);
    while(cin>>n){
        rep(i,0,n-1) {cin>>str; dir[i+1]=(str[0]=='F');}
        int cnt=0;
        rep(i,1,n) cnt+=dir[i];
        P best(n-cnt,1);//k==1
        rep(k,2,n){
            int m=0; // int  k=3;
            memset(rev,0,sizeof rev);
            memset(sum,0,sizeof sum);
            rep(i,1,n-k+1){
                if((check(i,k)+dir[i]) &1){
                    sum[i]=sum[i-1];
                }
                else{
                    m++;
                    rev[i]=1;
                    sum[i]=sum[i-1]+rev[i];
                }
                // cout<<i<<" "<<rev[i]<<" "<<check(i,k)<<" "<<sum[i]<<endl;
            }
            rep(i,n-k+2,n){
                if((check(i,k)+dir[i]) &1){sum[i]=sum[i-1];}
                else{m=0x3f3f3f3f;break;}
            }
            if(m<best.first) best=P(m,k);
            // else if(m==best.first&&k<best.second) best=P(m,k);
        }
        cout<<best.second<<" "<<best.first<<endl;
    }
    return 0;
}