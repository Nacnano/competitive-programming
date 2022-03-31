#include<bits/stdc++.h>
using namespace std;
const int mxN=1e5+10;

int p[mxN];
struct nd{
    int u,v,t;
};
bool cmp(nd a,nd b){
    
    return a.t > b.t;
};
vector<nd> edge;

int _find(int x)
{
    if(p[x]==x) return x;
    return p[x]=_find(p[x]);
}

int main(){

    int n,m,q;
    scanf("%d%d%d",&n,&m,&q);
    for(int i=0;i<m;i++)
    {
        int u,v,t;
        scanf("%d%d%d",&u,&v,&t);
        edge.push_back({u,v,t});
    }
    sort(edge.begin(), edge.end(),cmp);

    for(auto tmp:edge)
    {
        printf("%d ",tmp.t);
    }

    while(q--)
    {
        int x;
        scanf("%d",&x);
    }
}