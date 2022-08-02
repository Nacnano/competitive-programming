#include<bits/stdc++.h>
using namespace std;

int dis[505][505];
int cnt[505][505];
vector<pair<int,pair<int,int> > > road;

int main(){

    int n,m;
    scanf("%d%d",&n,&m);

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dis[i][j]=1e9;
    for(int i=1;i<=n;i++) dis[i][i]=0;

    while(m--)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        dis[u][v]=w;
        dis[v][u]=w;
        road.push_back({u,{v,w}});
    }

    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(dis[i][k]==1e9 || dis[k][j]==1e9) continue;
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }

    for(auto x:road)
    {
        int u=x.first, v=x.second.first, w=x.second.second;
        for(int k=1;k<=n;k++)
        {
            if(dis[k][u]+w==dis[k][v]) cnt[k][v]++;
            if(dis[k][v]+w==dis[k][u]) cnt[k][u]++;
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            int sum=0;
            for(int k=1;k<=n;k++)
            {
                if(dis[i][k]+dis[k][j] == dis[i][j]) sum+=cnt[i][k];
            }
            printf("%d ",sum);
        }
    }
}
