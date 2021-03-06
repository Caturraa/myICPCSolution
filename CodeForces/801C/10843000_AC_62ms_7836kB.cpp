#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+11;
const double oo = 1e12;
int a[maxn],b[maxn],n,p,tmp;
bool C(double x){
	double tot=x*p;
	for(int i = 0; i < n; i++){
		double e=b[i]-a[i]*x;
		if(e<0) tot+=e;
		if(tot<0) return 0;
	}
	return 1;
}
int main(){
	while(scanf("%d%d",&n,&p)!=EOF){
		for(int i = 0; i < n; i++){
			scanf("%d%d",&a[i],&b[i]);
		}
		if(C(oo)){
			printf("-1\n");
			continue;
		}
		double l=0,r=oo,mid;
		for(int i = 0; i < 80; i++){
			mid = l+(r-l)/2;
			if(C(mid)) l=mid;
			else r=mid;
		}
		printf("%.10lf\n",mid);
	}
	return 0;
}