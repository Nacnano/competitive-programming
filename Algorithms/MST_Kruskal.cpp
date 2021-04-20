#include<bits/stdc++.h>
using namespace std;

const int mx=100000;
int p[mx+5];
vector<pair<int,pair<int,int> > > edge;

int _find(int x)
{
    if(p[x]==x) return x;
    else return p[x]=_find(p[x]);
}

void _union(int x,int y)
{
    int px=_find(x);
    int py=_find(y);

    p[px]=p[py];
}

int main(){

    int n,m;
    scanf("%d%d",&n,&m);

    while(m--)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        edge.push_back({w,{u,v}});
    }

    sort(edge.begin(),edge.end());
    for(int i=1;i<=n;i++) p[i]=i;
    int cost=0;
    for(auto x: edge)
    {
        int u=x.second.first;
        int v=x.second.second;
        int w=x.first;

        int pu=_find(u);
        int pv=_find(v);

        if(pu!=pv)
        {
            cost+=w;
            _union(u,v);
            //Yep, this part of the code overlap the _union function by using _find() twice.
            //I am to lazy to recode it. So...
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
