#include<bits/stdc++.h>
using namespace std;

vector<int> forw[10005];
vector<int> bac[10005];
vector<int> leaf;
int stu[10005];

void fnd(int u)
{
    if(!forw[u].size())
    {
        leaf.push_back(u);
        return;
    }
    for(auto v:forw[u]) fnd(v);
}

void sum(int u,int st)
{
    if(!bac[u].size()) return;
    for(auto v:bac[u])
    {
        stu[v]+=stu[st];
        sum(v,st);
    }
}

int main(){

    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int v;
        scanf("%d",&v);
        forw[v].push_back(i);
        bac[i].push_back(v);
    }

    int m;
    scanf("%d",&m);
    while(m--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        stu[a]=b;
    }

    fnd(0);
    for(auto u:leaf) sum(u,u);
    for(int i=1;i<=n;i++) printf("%d\n",stu[i]);
}
