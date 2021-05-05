#include<bits/stdc++.h>
using namespace std;

int p[500010],dp[500010];

int main(){

    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&p[i]);

    priority_queue<pair<int,int> ,vector<pair<int,int> >,greater<pair<int,int> > > pq;

    dp[1]=p[1];
    pq.push({p[1],1});
    for(int i=2;i<=n;i++)
    {
        while(!pq.empty() && i-pq.top().second>k) pq.pop();
        dp[i]=pq.top().first+p[i];
        while(!pq.empty() && pq.top().first > dp[i]) pq.pop();
        pq.push({dp[i],i});
    }
    printf("%d",dp[n]);
}
