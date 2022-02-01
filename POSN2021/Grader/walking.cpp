#include<bits/stdc++.h>
using namespace std;

int a[2005][2005];
int d[5][3]={{1,0},{-1,0},{0,-1},{0,1}};
bool vis[2010][2010];
vector<int> path;
int n,m;

void dfs(pair<int,int> p)
{
    int x=p.first;
    int y=p.second;

    if(vis[y][x]) return;
    vis[y][x]=1;
    for(int i=0;i<4;i++)
    {
        int nx=x+d[i][0];
        int ny=y+d[i][1];

        if(nx>m || ny>n || nx<1 || ny<1 || vis[ny][nx]) continue;
        if(a[ny][nx]==a[y][x]+1)
        {
            if(i==0) path.push_back('R');
            else if(i==1) path.push_back('L');
            else if(i==2) path.push_back('U');
            else if(i==3) path.push_back('D');
            dfs({nx,ny});
            return;
        }
    }
    printf("%d\n",a[y][x]);
    return;
}

int main(){

    pair<int,int> st;
    scanf("%d%d",&n,&m);

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&a[i][j]);
            if(a[i][j]==1) st={j,i};
        }
    }

    dfs(st);
    for(int i=0;i<path.size();i++) printf("%c",path[i]);
}
