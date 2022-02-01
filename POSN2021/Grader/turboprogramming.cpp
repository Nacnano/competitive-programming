#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int> > g[1005];
int ans[1005];

int main(){

    int n,m,q;
    scanf("%d%d%d",&n,&m,&q);
    while(m--)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        g[u].push_back({v,w});
    }

    for(int i=1;i<=n;i++) ans[i]=INT_MAX;

    priority_queue<pair<int,int > > pq;
    ans[1]=0;
    pq.push({1,0});
    while(!pq.empty())
    {
        int u=pq.top().first;
        int dis=pq.top().second;
        pq.pop();

        for(auto v: g[u])
        {
            if(dis+v.second < ans[v.first])
            {
                ans[v.first]=dis+v.second;
                pq.push({v.first,ans[v.first]});
            }
        }
    }

    while(q--)
    {
        int x;
        scanf("%d",&x);
        if(ans[x]!=INT_MAX) printf("%d\n",ans[x]);
        else printf("-1\n");
    }
}
