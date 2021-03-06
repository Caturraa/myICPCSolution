#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;
vector<int> prime;
bool isPrime[10000]; 
bool vis[10000];
int temp;
int T,s,e;
vector<int> ans;
int query(int i,int a){
	if(i==1) return a%10000-a%1000;
	if(i==2) return a%1000-a%100;
	if(i==3) return a%100-a%10;
	if(i==4) return a%10;
}
int DP[10006];
int pre[123456];
queue<int> q;
int main(){
	memset(isPrime,true,sizeof isPrime);
	isPrime[0] = 0; isPrime[1] = 0;
	for(int i = 2; i*i<10000; i++){
		if(isPrime[i]){
			for(int j = 2*i; j < 10000; j+=i){
				isPrime[j] = 0;
			}
		}
	}
	int T; scanf("%d",&T);
	while(T--){
		scanf("%d %d",&s,&e);
		memset(vis,0,sizeof vis);
		memset(DP,0,sizeof DP);
		while(!q.empty()) q.pop();
		q.push(s); vis[s] = 1;
		int cur;
		while(!q.empty()){
			cur = q.front(); q.pop();
			for(int i = 1; i <= 4; i++){
				if(DP[e]!=0) break;
				for(int j = 0; j < 10; j++){
					int temp = cur-query(i,cur)+j*(int)pow(10.0,4.0-i);
					if(DP[temp] == 0 && isPrime[temp] &&!vis[temp]){
						if(temp<1000) continue;
						q.push(temp);
						vis[temp] = 1;
						DP[temp] = DP[cur]+1; 
						//pre[temp] = cur;
					}
				}
			}
		}
		//cur = e;
		//while(1){
		//	if(cur==s)
		//		break;
		//	printf("%d\n",cur);
		//	cur = pre[cur];
		//}
		printf("%d\n",DP[e]);
	}
	return 0;
} 