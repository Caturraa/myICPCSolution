#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
const int maxn = 5000;
int a[maxn],n;
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int sum=0;
		for(int i = 0; i < n; i++){
			scanf("%d",&a[i]);sum+=a[i];
		} 
		for(int i = 1; i < n; i++){
			a[0]^=a[i];
		}
		if((a[0]==0&&sum!=n)||(a[0]!=0&&sum==n)) printf("Brother\n");
		else printf("John\n");
	}
	return 0;
}