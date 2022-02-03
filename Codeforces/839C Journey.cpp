#include<bits/stdc++.h>
using namespace std;

vector<int> g[100005];
int dis[100005];
double sum=0;

void dfs(int u,int s,double prob)
{
    if(g[u].size()==1 && s!=-1)
    {
        sum+=prob*(double)dis[u];
        return;
    }

    for(auto v:g[u])
    {
        if(v==s) continue;

        dis[v]=dis[u]+1;
        if(s==-1) dfs(v,u,prob/(double)(g[u].size()));
        else  dfs(v,u,prob/(double)(g[u].size()-1));
    }
}

int main(){

    int n;
    scanf("%d",&n);
    n--;
    while(n--)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dis[1]=0;
    dfs(1,-1,1.0);
    printf("%.15lf",sum);
}
