#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pii pair<int,int>
#define f first
#define s second

const int maxN=100005;

void solve(){
	int n, m, a[maxN], ans=0;
	priority_queue<pii> pqmid, pqedge;
	cin >> n >> m >> a[0];

	for(int i=1;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n);
	pqedge.push({a[0]-1, 1});
	pqedge.push({n-a[n-1], 1});

	int t=1;
	while(!pq.empty()){
		int now = pq.top();
		pq.pop();

		if(now-2*t>0){
			ans+=now-1;
		}
		t+=2;
	}
	cout << ans << "\n";
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt","w", stdout);
	#endif

	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int t=1;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}