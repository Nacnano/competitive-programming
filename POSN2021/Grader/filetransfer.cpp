#include<bits/stdc++.h>
using namespace std;

vector<int> g[1005];
bool vis[1005];

void dfs(int x)
{
    if(vis[x]) return;
    vis[x]=1;
    for(auto v:g[x])
    {
        if(vis[v]) continue;
        dfs(v);
    }
    return;
}

int main(){

    int n,m,q;
    scanf("%d%d%d",&n,&m,&q);
    while(m--)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
    }

    while(q--)
    {
        int st,ed;
        scanf("%d%d",&st,&ed);

        dfs(st);

        if(vis[ed]) printf("Yes\n");
        else printf("No\n");

        for(int i=1;i<=n;i++) vis[i]=0;
    }
}
