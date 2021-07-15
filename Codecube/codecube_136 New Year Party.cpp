// This problem is a bit...
// Well, Fuck Off

#include<bits/stdc++.h>
using namespace std;

vector<int> g[405];
int col[405];
int num[405];

void dfs(int u,int set)
{
	if(col[u]) return;
	col[u]=set;
	num[set]++;
	
	for(auto v: g[u])
	{
		if(col[v]) continue;
		dfs(v,set);
	}
}


void solve()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) col[i]=0,num[i]=0,g[i].clear();
	
	while(m--)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	int cnt=1;
	for(int i=1;i<=n;i++) if(!col[i]) dfs(i,cnt++);
	
	if(cnt>3) printf("-1\n");
	else if(cnt==3) printf("%d\n",abs(num[1]-num[2]));
	else if(cnt==2) printf("%d\n",num[1]%2);
	else if(n==2) printf("0\n");
	else if(n==1) printf("1\n");
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--) solve();
}
