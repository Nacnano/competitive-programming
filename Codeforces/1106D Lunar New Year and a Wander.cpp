#include<bits/stdc++.h>
using namespace std;

priority_queue<int> pq;
vector<int> g[100005];
vector<int> ans;
bool used[100005];


int main(){

    int n,m;
    scanf("%d%d",&n,&m);
    while(m--)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        if(v<u) swap(u,v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    pq.push({-1});
    while(!pq.empty())
    {
        int u=-pq.top();
        pq.pop();

        if(used[u]) continue;
        used[u]=1;
        ans.push_back(u);

        for(auto v:g[u])
        {
            if(used[v]) continue;
            pq.push(-v);
        }
    }

    for(auto x:ans) printf("%d ",x);

}
