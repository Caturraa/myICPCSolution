#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+11;
const int oo = 0x7fffffff;
int to[maxn<<1],nxt[maxn<<1],cap[maxn<<1],flow[maxn<<1];
int head[maxn],tot;
void init(){
	memset(head,-1,sizeof head);
	tot=0;
}
void add(int u,int v,int w){
	to[tot]=v;
	nxt[tot]=head[u];
	cap[tot]=w;
	flow[tot]=0;
	head[u]=tot++;
	swap(u,v);
	to[tot]=v;
	nxt[tot]=head[u];
	cap[tot]=w;
	flow[tot]=0;
	head[u]=tot++;
}
int n,m,s,t;
int dis[maxn],pre[maxn],cur[maxn],gap[maxn];//pre 父边 
bool vis[maxn];
//struct QUEUE{
//	int que[maxn];
//	int front,rear;
//	void init(){front=rear=0;}
//	void push(int u){que[rear++]=u;}
//	int pop(){return que[front++];}
//	bool empty(){return front==rear;}
//}que;
struct STACK{
	int stk[maxn];
	int front,rear;
	void init(){front=rear=0;}
	void push(int u){stk[++rear]=u;}
	int pop(){return stk[--rear];}
	bool empty(){return front==rear;}
}stk;
int que[maxn];
void bfs(){
	memset(vis,0,sizeof vis);
	
	int front=0,rear=1;
//	que.init();
//	que.push(t);
	que[0]=t;
	vis[t]=1;dis[t]=0;
	while(front^rear){
		int u = que[front++];
		for(int i = head[u]; ~i; i = nxt[i]){
			register int v=to[i],c=cap[i^1],f=flow[i^1];
			if(!vis[v]&&c>f){
				vis[v]=1;
				dis[v]=dis[u]+1;
//				que.push(v);
				que[rear++]=v;
			}
		}
	}
}
int aug(){
	int u=t,ans=oo;
	while(u!=s){
		ans=min(ans,cap[pre[u]]-flow[pre[u]]);
		u=to[pre[u]^1];
	}
	u=t;
	while(u!=s){
		flow[pre[u]]+=ans;
		flow[pre[u]^1]-=ans;
		u=to[pre[u]^1];
	}
	return ans;
}
int isap(){
	int ans=0;
	bfs();
	memset(gap,0,sizeof gap);
	memcpy(cur,head,sizeof head);
	for(int i = 1; i <= n; i++) gap[dis[i]]++;
	int u = s;
	//memset(cur,0,sizeof cur);
	while(dis[s]<n){
		if(u==t){
			ans+=aug();
			u=s;
		}
		bool ok=0;
		for(int i = cur[u]; ~i; i = nxt[i]){
			int v=to[i],c=cap[i],f=flow[i];
			if(c>f&&dis[u]==dis[v]+1){
				ok=1;
				pre[v]=i;
				cur[u]=i;
				u=v;
				break;
			}
		}
		if(!ok){
			int mn=n-1;
			for(int i = head[u]; ~i; i = nxt[i]){
				int v=to[i],c=cap[i],f=flow[i];
				if(c>f) mn=min(mn,dis[v]);
			}
			if(--gap[dis[u]]==0) break;
			dis[u]=mn+1;gap[dis[u]]++;
			cur[u]=head[u];
			if(u!=s) u=to[pre[u]^1];
		}
	}
	return ans;
}
int main(){
	int T,x,y,u,v,w; scanf("%d",&T);
	while(T--){
		init();
		scanf("%d%d",&n,&m);
		int mn=oo,mx=-oo;
		int mni=1,mxi=1;
		for(int i = 1; i <= n; i++){
			scanf("%d%d",&x,&y);
			if(x<mn){
				mn=x;
				mni=i;
			}
			if(x>mx){
				mx=x;
				mxi=i;
			}
		}
		s=mni,t=mxi;
		for(int i = 1; i <= m; i++){
			scanf("%d%d%d",&u,&v,&w);
			add(u,v,w);
		}
		printf("%d\n",isap());
	}
//    while(scanf("%d%d",&m,&n)!=EOF){
//        init();
//        int u,v,w;
//        for(int i = 1; i <= m; i++){
//            scanf("%d%d%d",&u,&v,&w);
//            add(u,v,w);
//        }
//        s=1,t=n;
//        printf("%d\n",isap());
//    }
    return 0;
}