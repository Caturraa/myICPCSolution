#include <stdio.h>
#include <string.h>
#define MN 10005
#define ME 100005
#define r register
#define clr(a) memset((a),0,sizeof (a)) 
int nxt[ME],to[ME],head[MN],ord[MN],low[MN],dfsn,st[MN],sn,en,scnt,v,e;
bool inz[MN];
inline void ins(int x,int y){to[++en]=y,nxt[en]=head[x],head[x]=en;}
void init(){
	 clr(head);clr(ord);clr(low); 
	 sn=en=dfsn=scnt=0; 
}
void tj(int u){
    ord[u]=low[u]=++dfsn;inz[st[sn++]=u]=1;
    for (r int i=head[u]; i; i=nxt[i]){
        if (!ord[to[i]]) tj(to[i]);
        if (inz[to[i]]&&low[to[i]]<low[u]) low[u]=low[to[i]]; 
    }if (ord[u]==low[u]) for(++scnt; st[sn]!=u;) inz[st[--sn]]=0;
}
int main(){
	while(scanf("%d%d",&v,&e)!=EOF){
		if(!v)break; 
		for (r int i=1,x,y; i<=e; ++i) scanf("%d%d",&x,&y),ins(x,y);
		for (r int i=1; i<=v; ++i) if (!ord[i]) tj(i);
		printf("%s\n",scnt==1?"Yes":"No");
		init(); 
	}
	return 0;
    
}