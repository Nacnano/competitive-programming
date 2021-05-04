#include<bits/stdc++.h>
using namespace std;

pair<int,pair<int,int> > pos[15];
pair<int,pair<int,int> > val[15];
bool vis[15];
int n,m;
int ans=INT_MAX;
int cost(int x1,int y1,int z1,int x2,int y2,int z2)
{
    int dx=x1-x2;
    int dy=y1-y2;
    int dz=z1-z2;

    return dx*dx+dy*dy+dz*dz;
}

void sol(int x,int y,int z,int a,int b,int c,int v)
{
    if(a>=n && b>=n && c>=n)
    {
        ans=min(ans,v);
        return;
    }
    for(int i=1;i<=m;i++)
    {
        if(vis[i]==1) continue;
        vis[i]=1;
        int nx=pos[i].first;
        int ny=pos[i].second.first;
        int nz=pos[i].second.second;
        sol(nx,ny,nz,a+val[i].first,b+val[i].second.first,c+val[i].second.second,v+cost(x,y,z,nx,ny,nz));
        vis[i]=0;
    }
}

int main(){


    scanf("%d",&n);
    int x0,y0,z0;
    scanf("%d%d%d",&x0,&y0,&z0);

    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&pos[i].first,&pos[i].second.first,&pos[i].second.second);
        scanf("%d%d%d",&val[i].first,&val[i].second.first,&val[i].second.second);
    }
    sol(x0,y0,z0,0,0,0,0);
    printf("%d",ans);
}
