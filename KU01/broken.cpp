#include<bits/stdc++.h>
using namespace std;

char s[35][35];
int vis[35][35];
int ans=0;

void dfs(int x,int y)
{
	if(vis[y][x]) return;
	vis[y][x]=1;
	ans++;
	
	if(s[y-1][x]=='.' && y>=1) dfs(x,y-1);
	if(s[y][x-1]=='.' && x>=1) dfs(x-1,y);
}

int main(){
	ios_base::sync_with_stdio(0);
	
	int n;
	scanf("%d",&n);
	
	for(int i=0;i<n;i++) scanf("%s",&s[i]);
	dfs(n-1,n-1);
	
	printf("%d",ans);
	
}
