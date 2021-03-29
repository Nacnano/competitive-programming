#include<bits/stdc++.h>
using namespace std;
queue<pair<int,int> > q;
char s[110][110];
int dist[110][110];

int main(){
	
	int a,b;
	scanf("%d%d",&a,&b);
	
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			scanf(" %c",&s[i][j]);
		}
	}
	
	q.push({1,1});
	dist[1][1]=1;
	while(!q.empty())
	{
		
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		
		if(s[y][x]=='B')
		{
			if(dist[y+1][x]>0)
			{
				printf("%d\n",dist[y][x]+1);
				printf("%d %d",y+1,x);
				break;
			}
			
			if(dist[y][x+1]>0)
			{
				printf("%d\n",dist[y][x]+1);
				printf("%d %d",y,x+1);
				break;
			}
			dist[y+1][x]=dist[y][x]+1;
			dist[y][x+1]=dist[y][x]+1;
			
			q.push({x+1,y});
			q.push({x,y+1});	
		}
		
		if(s[y][x]=='R')
		{
			if(dist[y][x+1]>0)
			{
				printf("%d\n",dist[y][x]+1);
				printf("%d %d",y,x+1);
				break;
			}
			
			dist[y][x+1]=dist[y][x]+1;
			
			q.push({x+1,y});
		}
		
		if(s[y][x]=='D')
		{
			if(dist[y+1][x]>0)
			{
				printf("%d\n",dist[y][x]+1);
				printf("%d %d",y+1,x);
				break;
			}
			
			dist[y+1][x]=dist[y][x]+1;
			
			q.push({x,y+1});
		}	
	}
}
