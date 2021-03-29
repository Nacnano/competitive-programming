#include<bits/stdc++.h>
using namespace std;

int n,m,t;
int rd[100][110];
int ans[110];

void path(int time,int lane)
{
	if(time==t)
	{
		for(int i=0;i<t;i++)
		{
			printf("%d\n",ans[i]);
		}
		return;
	}
	
	if(rd[time+1][lane-1]==0 && lane-1>=1)
	{
		ans[time]=1;
		path(time+1,lane-1);
	}
	if(rd[time+1][lane+1]==0 && lane+1<=n)
	{
		ans[time]=2;
		path(time+1,lane+1);
	}
	if(rd[time+1][lane]==0)
	{
		ans[time]=3;
		path(time+1,lane);
	}
}

main(){
	
	scanf("%d%d%d",&n,&m,&t);
	
	for(int i=1;i<=t;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&rd[i][j]);
		}
	}
	path(0,m);
	
}
