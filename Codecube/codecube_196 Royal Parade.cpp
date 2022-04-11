#include<bits/stdc++.h>
using namespace std;

long long dis[5][100010];
bool vis[100010], used[100010];
vector<pair<int,int> > g[100010];

void gen(int node, int lv)
{
    priority_queue<pair<long long,int>, vector<pair<long long,int> >, greater<pair<long long,int> > > pq;
    dis[lv][node]=0;
    pq.push({0,node});
    while(!pq.empty()){
        int u = pq.top().second;
        long long dnow = pq.top().first;
        pq.pop();
        for(auto tmp: g[u]){
            if(dnow + tmp.second <= dis[lv][tmp.first])
            {
                if(used[tmp.first]==1) continue;
                dis[lv][tmp.first] = dnow + tmp.second;
                pq.push({dis[lv][tmp.first],tmp.first});
            }
        }
    }

}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n,m,a,b,c,d;
    cin >> n >> m;
    while(m--){
        int u,v,w;
        cin >> u >> v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    cin >> a >> b >> c >> d;

    for(int i=0;i<3;i++) for(int j=0;j<=n;j++) dis[i][j]=1e18;
    gen(a,0);
    gen(b,1);

    for(int i=1;i<=n;i++) if(dis[0][b] == dis[0][i] + dis[1][i]) used[i]=1;

    gen(c,2);

    if(dis[2][d]==1e18) cout << "-1";
    else cout << dis[2][d];
}