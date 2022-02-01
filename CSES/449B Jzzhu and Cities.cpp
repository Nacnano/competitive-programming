#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int> > g[100010];
pair<int,int> tr[100010];
bool vis[100010];
long long dis[100010];

int main(){

    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    while(m--)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }

    for(int i=1;i<=n;i++) dis[i]=2e18;
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>  > pq;
    pq.push({0,1});
    dis[1]=0;

    while(!pq.empty())
    {
        int u=pq.top().second;
        long long d=pq.top().first;
        pq.pop();
        for(auto x: g[u])
        {
            if(d+x.second < dis[x.first])
            {
                dis[x.first]=d+x.second;
                pq.push({dis[x.first],x.first});
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        if(dis[i]!=2e18) vis[i]=1;
        else vis[i]=0;
    }

    for(int i=0;i<k;i++)
    {
        int s,y;
        scanf("%d%d",&s,&y);
        tr[i]={s,y};
        if(vis[s]==0)
        {
            dis[s]=min(dis[s],(long long)y);
        }
    }

    int ans=0;
    for(int i=0;i<k;i++)
    {
        if(vis[tr[i].first]==0 && dis[tr[i].first] < tr[i].second) ans++;
        else if(vis[tr[i].first]==1 && dis[tr[i].first] <= tr[i].second) ans++;
    }
    printf("%d",ans);
}
