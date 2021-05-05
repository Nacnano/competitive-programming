#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int> > g[100010];
bool vis[100010];
int xo[100010];
void dfs(int u)
{
    if(vis[u]) return;
    vis[u]=1;

    for(auto x:g[u])
    {
        int v=x.first;
        int w=x.second;

        xo[v]=xo[u]^w;
        dfs(v);
    }
}

int main(){

    int n,m;
    scanf("%d%d",&n,&m);
    n--;
    while(n--)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }

    dfs(1);
    while(m--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%d\n",xo[a]^xo[b]);
    }
}
