#include<bits/stdc++.h>
using namespace std;

const int mx=100000;
vector<pair<int,int> > g[mx+5];
priority_queue<pair<int,int> > pq;
bool vis[mx+5];

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

    //Actually, we can start from any node in the graph. But I chose to start from node 1 because...
    pq.push({0,1});
    int cost=0;
    while(!pq.empty())
    {
        int u=pq.top().second;
        int w=-pq.top().first;
        pq.pop();

        if(vis[u]) continue;
        vis[u]=1;
        cost+=w;

        for(auto x:g[u])
        {
            int v=x.first;
            int w=x.second;
            if(!vis[v]) pq.push({-w,v});
        }
    }
    printf("%d",cost);
}


/*
6 9
1 2 3
1 4 5
2 3 8
2 4 2
2 5 10
3 5 4
3 6 6
4 5 11
5 6 7
*/
