#include<bits/stdc++.h>
using namespace std;

int dis[105][105];
char a[105][105];

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf(" %c",&a[i][j]);
	
	queue<pair<int,pair<int,int> > > q;
	q.push({1,{1,1}});
	while(!q.empty())
	{
		int t=q.front().first;
		int x=q.front().second.first;
		int y=q.front().second.second;
		q.pop();
		
		if(dis[y][x])
		{
			if(dis[y][x]==t-2) continue;
			printf("%d\n%d %d",t,y,x);
			return 0;
		}
		
		dis[y][x]=t;
		if(x<m && (a[y][x]=='R' || a[y][x]=='B')) q.push({t+1,{x+1,y}});
		if(y<n && (a[y][x]=='B' || a[y][x]=='D')) q.push({t+1,{x,y+1}});
		if(y>=2 && (a[y-1][x]=='D' || a[y-1][x]=='B')) q.push({t+1,{x,y-1}});
		if(x>=2 && (a[y][x-1]=='R' || a[y][x-1]=='B')) q.push({t+1,{x-1,y}});
	}
}
