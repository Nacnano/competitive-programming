#include<bits/stdc++.h>
using namespace std;

priority_queue<pair<double ,pair<int,int> > > pq;
int p[1005];

int _find(int x)
{
    if(p[x]==x) return x;
    else return p[x]=_find(p[x]);
}

int main(){

    int n,m;
    scanf("%d%d",&n,&m);
    while(m--)
    {
        int u,v;
        double w;
        scanf("%d%d%lf",&u,&v,&w);
        pq.push({-w,{u,v}});
    }

    for(int i=1;i<=n;i++) p[i]=i;

    double ans=0;
    while(!pq.empty())
    {
        double w=pq.top().first;
        int u=pq.top().second.first;
        int v=pq.top().second.second;
        pq.pop();
        int pu=_find(u);
        int pv=_find(v);

        if(pu!=pv)
        {
            ans+=-w;
            p[pu]=pv;
        }
    }
    printf("%.3lf",ans);
}
