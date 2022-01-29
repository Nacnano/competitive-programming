#include<bits/stdc++.h>
using namespace std;

int a[100010];
int vis[100010];
int ans=0;

void dfs(int st, int x, int cnt)
{
	if(vis[x]) return;
	vis[x]=1;
	
	if(x==st)
	{
		ans=max(ans,cnt);
		return;
	}
	dfs(st,a[x],cnt+1);
	return;	
}

int main(){
	ios_base::sync_with_stdio(NULL); cin.tie(NULL);
	
	int n;
	scanf("%d",&n
	);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	
	for(int i=1;i<=n;i++)
	{
		if(a[i]==i) continue;
		if(!vis[i])
		{
			dfs(i,a[i],1);
		}
	}
	
	printf("%d",ans);
	return 0;
}
