#include <bits/stdc++.h>
using namespace std;

int m,n,a,b,c;
bitset<2010> sa[10010];
bitset<2010> visited[10010];
char s[2010];
queue<pair<int,int> > q;
int d[5][2]={{1,0},{-1,0},{0,-1},{0,1}};

void solve(int x,int y)
{
    q.push(make_pair(x,y));
    int ul=INT_MAX,lr=-1,cu=0,cl=0;
    
    while(!q.empty())
    {
        x = q.front().first;
		y = q.front().second;
        q.pop();
        
        if(x+y<ul)
		{
			ul = x+y;
			cu = 1;
		}
        else if(x+y==ul)cu=0;
        
        if(x+y>lr)
		{
			lr = x+y; cl = 1;
		}
        else if(x+y==lr)cl=0;
        
        for(int i = 0;i < 4;i++)
        {
	    	int ax = x+d[i][0];
			int ay = y+d[i][1];
				
	        if(ax<0 || ax>=m || ay<0 || ay>=n) continue;
	        if(sa[ax][ay] == 0 || visited[ax][ay]) continue;
	            
	        visited[ax][ay] = true;
	        q.push(make_pair(ax,ay));
		}
    }
    
    if(cu==1 && cl==1) a++;
    else if(cu==1 || cl==1) c++;
    else b++;
}

main()
{
    scanf("%d%d",&n,&m);

    for(int i = 0;i < m;i++)
	{
		scanf("%s",s);
		for(int j=0;j<n;j++)
		{
			if(s[j]=='1')
			{
				sa[i][j]=true;
			}
		}
	}
    for(int i = 0;i < m;i++)
	{
		for(int j = 0;j < n;j++)
	    {
	        if(sa[i][j]==0 || visited[i][j])continue;
	        visited[i][j]=true;
	        solve(i,j);
	    }
	}
    printf("%d %d %d",a,b,c);
}