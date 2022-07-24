#include<bits/stdc++.h>
using namespace std;
const int maxN = 100000;
int a[maxN], n, m, k;

bool check(int mn, int mx){
	int cnt=0;
	vector<int> v;
	for(int i=1;i<=k;i++){
		if(a[i]>=2*mn){
			v.push_back(a[i]/mn);
		}
	}

	long long sum=0;
	sort(v.begin(),v.end());
	for(auto free: v){
		sum+=free;
		if(sum>=mx+2 || sum==mx) return true;
		else if(sum==mx+1){

			if(free==2) sum-=2;
			else if(free>=3) return true;
		}
	}
	return false;
}


void solve(){
	bool can=0;
	cin >> n >> m >> k;
	int mn=min(n,m), mx=max(n,m);
	for(int i=1;i<=k;i++) {
		cin >> a[i];
	}

	can=check(mn, mx) | check(mx, mn);
	cout << (can ? "Yes\n" : "No\n");
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