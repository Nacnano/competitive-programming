#include<bits/stdc++.h>
using namespace std;

int n,m;
int cat[100005];
bool vis[100005];
vector<int> g[100005];
int cnt=0;

void dfs(int u,int s,int c)
{
    if(c>m) return;
    if(s!=-1 && g[u].size()==1) cnt++;
    for(auto v: g[u])
    {
        if(v==s) continue;
        else
        {
            if(cat[v])
            {
                dfs(v,u,c+1);
            }
            else dfs(v,u,0);
        }
    }

}
int main(){

    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        cat[i]=x;
    }
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1,-1,cat[1]);
    printf("%d",cnt);
}
