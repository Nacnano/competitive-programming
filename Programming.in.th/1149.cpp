#include<bits/stdc++.h>
using namespace std;

int a[1000][1001];
int dis[1000][1001];
int d[5][3]={{1,0},{-1,0},{0,-1},{0,1}};
int xs=-1,ys,xe,ye;

int main(){
	
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
			
			if(!a[i][j])
			{
				if(xs==-1) xs=j,ys=i;
				else xe=j, ye=i;
			}
			dis[i][j]=INT_MAX;
		}
	}
	
	priority_queue<pair<int,pair<int,int> > > q;
	q.push({0,{xs,ys}});
		
	while(!q.empty())
	{
		int w=-q.top().first;
		int x=q.top().second.first;
		int y=q.top().second.second;
		q.pop();
		if(x==xe && y==ye)
		{
			printf("%d",w);
			break;
		}
		
		for(int i=0;i<4;i++)
		{
			int nx=x+d[i][0];
			int ny=y+d[i][1];
			if(nx>n || nx<0 || ny<0 || ny>n) continue;
				
			if(dis[ny][nx]<=max(w,a[ny][nx])) continue;
			dis[ny][nx]=max(w,a[ny][nx]);
			q.push({-dis[ny][nx],{nx,ny}});
		}
	}
	return 0;
}
