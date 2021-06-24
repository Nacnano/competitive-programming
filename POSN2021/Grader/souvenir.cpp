#include<bits/stdc++.h>
using namespace std;

char a[1005][1005];
pair<int,int> st,ed;
int dis1[1005][1005];
int dis2[1005][1005];
vector<pair<int,int> > v;

int d[5][3]={{1,0},{-1,0},{0,-1},{0,1}};

int main(){
	
	int n,m;
	scanf("%d%d",&n,&m);
	
	for(int i=0;i<n;i++)
	{
		scanf("%s",&a[i]);
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			dis1[i][j]=INT_MAX;
			dis2[i][j]=INT_MAX;
			
			if(a[i][j]=='A') st={j,i};
			else if(a[i][j]=='B') ed={j,i};
			else if(a[i][j]=='C') v.push_back({j,i});
		}
	}
	
	
	queue<pair<int,int> > q;
	q.push({st.first,st.second});
	dis1[st.second][st.first]=0;
	while(!q.empty())
	{
		int x=q.front().first, y=q.front().second;
		q.pop();
		
		for(int i=0;i<4;i++)
		{
			int nx=x+d[i][0];
			int ny=y+d[i][1];
			
			if(nx<0 || nx>=m || ny<0 || ny>=n) continue;
			if(a[ny][nx]=='#') continue;
			
			if(dis1[ny][nx] > dis1[y][x]+1)
			{
				dis1[ny][nx]=dis1[y][x]+1;
				q.push({nx,ny});
			}
		}
	}
	
	for(auto it: v)
	{
		dis2[it.second][it.first]=dis1[it.second][it.first];
		q.push({it.first,it.second});
	}
	
	while(!q.empty())
	{
		int x=q.front().first, y=q.front().second;
		q.pop();
		
		for(int i=0;i<4;i++)
		{
			int nx=x+d[i][0];
			int ny=y+d[i][1];
			
			if(nx<0 || nx>=m || ny<0 || ny>=n) continue;
			if(a[ny][nx]=='#') continue;
			
			if(dis2[ny][nx] > dis2[y][x]+1)
			{
				dis2[ny][nx]=dis2[y][x]+1;
				q.push({nx,ny});	
			}
		}
	}
	
	if(dis2[ed.second][ed.first]!=INT_MAX) printf("%d",dis2[ed.second][ed.first]);
	else printf("-1");
}
