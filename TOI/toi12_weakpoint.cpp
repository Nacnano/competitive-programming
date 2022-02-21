#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> g[500010];
int cnt[500010];
bool vis[500010];

dfs(int u)
{
	if(vis[u]==1) return 0;
	if(u==m) return -1;
	vis[u]=1;
	
	int tmp=1, chk=0;
	for(auto v:g[u])
	{
		int w=dfs(v);
		if(w==-1) chk=1;
		else tmp+=w;
	}
	cnt[u]=tmp-1;
	if(chk==1) return -1;
	return tmp;
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(0);

	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		g[v].push_back(u);
		g[u].push_back(v);
	}
	
	cnt[m]=-1e9;
	for(auto v:g[m]) dfs(v);
	
	int ans1=0,ans2=0;
	for(int i=1;i<=n;i++)
	{
		if(ans2<cnt[i])
		{
			ans2=cnt[i];
			ans1=i;
		}
		else if(ans2==cnt[i]) ans2=min(ans1,i);
	}
	if(ans2>0) printf("%d\n%d",ans1,ans2);
	else if(m==1) printf("0\n2");
	else printf("0\n1");
	
}
