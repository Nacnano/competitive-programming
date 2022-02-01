#include<bits/stdc++.h>
using namespace std;

int p[500010],h[500010],dp[500010];

int main(){

    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&p[i]);
    for(int i=1;i<=n;i++) scanf("%d",&h[i]);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;

    dp[1]=0;
    pq.push({0,1});
    for(int i=2;i<=n;i++)
    {
        while(!pq.empty() && i-pq.top().second>k) pq.pop();
        dp[i]=pq.top().first+p[pq.top().second];
        while(!pq.empty() && pq.top().first > dp[i]) pq.pop();
        pq.push({dp[i],i});
    }


    for(int i=1;i<=n;i++) printf("%d\n",dp[i]);
}

/*
8
2
1 2 1 4 1 4 2 8
3 5 1 0 2 0 8 7
Ans: 9
*/
