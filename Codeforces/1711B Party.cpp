#include<bits/stdc++.h>
using namespace std;
const int maxN = 200000;
int a[maxN], n, m, deg[maxN], mn1, mn2, vis[maxN];
vector<int> v[maxN];	

void dfs(int u){
	if(vis[u]) return;
	vis[u]=1;

	if(deg[u]%2==0) {
		if(a[u]<mn1) {
			mn2=mn1;
			mn1=a[u];
		}
		else if(a[u]<mn2){
			mn2=a[u];
		}
	}	
	for(auto v:v[u]){
		dfs(v);
	}
}


void solve(){
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	
	for(int i=0;i<m;i++){
		int a, b;
		cin >> a >> b;
		deg[a]++, deg[b]++;
		v[a].push_back(b);
		v[b].push_back(a);
	}



	if(m%2==0){
		cout << "0\n";
	}
	else{
		int ans=0;
		for(int i=1;i<=n;i++){
			mn1=INT_MAX;
			mn2=INT_MAX;
			if(!vis[i]) dfs(i);
			// cout << mn2 << " " << mn1 << "\n";
			if(mn1!=INT_MAX) ans+=mn1;
			if(mn2!=INT_MAX) ans+=mn2;
		}
		cout << ans << "\n";
	}

	for(int i=1;i<=n;i++) deg[i]=0, vis[i]=0, v[i].clear();
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	ios_base::sync_with_stdio(0), cin.tie(NULL);

	int t=1;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}