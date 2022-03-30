#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int> > g[100005];
int dis[100005];
bool vis[100005];
int bac[100005];

int main(){

    int n,m;
    scanf("%d%d",&n,&m);
    while(m--)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }

    int s,e;
    scanf("%d%d",&s,&e);

    for(int i=1;i<=n;i++) dis[i]=INT_MAX;
    priority_queue<pair<int,int>> pq;

    dis[s]=0;
    pq.push({0,s});
    while(!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(auto x:g[u])
        {
            int v=x.first;
            int w=x.second;
            if(dis[u]+w < dis[v])
            {
                dis[v]=dis[u]+w;
                pq.push({-dis[v],v});
                bac[v]=u;
            }
        }
    }

    vector<int> path;
    int now=e;
    while(now!=s)
    {
        path.push_back(now);
        now=bac[now];
    }
    path.push_back(s);
    printf("Distance %d\nPath ",dis[e]);
    for(int i=path.size()-1;i>=0;i--) printf("%d ",path[i]);

}
