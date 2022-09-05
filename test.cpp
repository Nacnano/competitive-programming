#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
struct A {
	int v,w;
	bool operator < (const A& o) const {
		return w > o.w;
	}
};
vector<A> adj[N];
int d[N];
int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt","w", stdout);
	#endif
	int n,m;
	cin >> n >> m;
	while(m--) {
		int u,v,w;
		cin >> u >> v >> w;
		u[adj].push_back({v, w});
	}
	memset(d, 0x3f, sizeof(d));
	d[0] = 0;
	priority_queue<A> pq;
	pq.push({0,0});
	while(!pq.empty()) {
		int u = pq.top().v, w = pq.top().w;
		pq.pop();
		for(auto& x : adj[u] ) {
			if(d[x.v] > w + x.w) {
				d[x.v] = w+x.w;
				pq.push({x.v, d[x.v]});
			}
		}
	}
	cout << (d[n-1]);
	return 0;
}