#include<bits/stdc++.h>
using namespace std;

pair<int,int> point[1005];
int p[1005];

long long dis(int i,int j)
{
    return (long long) (point[i].first-point[j].first)*(point[i].first-point[j].first)+(point[i].second-point[j].second)*(point[i].second-point[j].second);
}

int _find(int x)
{
    if(p[x]==x) return x;
    else return p[x]=_find(p[x]);
}

int main(){

    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d%d",&point[i].first,&point[i].second);

    priority_queue<pair<long long,pair<int,int> > > pq;
    for(int i=1;i<=n;i++)  for(int j=i+1;j<=n;j++) pq.push({-dis(i,j),{i,j}});

    for(int i=0;i<=n;i++) p[i]=i;

    vector<long long> mst;
    while(!pq.empty())
    {
        int p1=pq.top().second.first;
        int p2=pq.top().second.second;
        long long w= -pq.top().first;

        pq.pop();
        int pp1=_find(p1);
        int pp2=_find(p2);

        if(pp1!=pp2)
        {
            p[pp1]=pp2;
            mst.push_back(w);
        }
    }

    printf("%lld\n",mst[n-k-1]);
}
