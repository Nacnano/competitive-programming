#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pii pair<int,int>
#define f first
#define s second

const ll p=1e9+7;
const int maxN=200005;

void solve(){
	ll n, c, d, q[maxN];
	cin >> n >> c >> d;
	for(int i=0;i<n;i++){
		cin >> q[i];
	}
	sort(q, q+n);

	int l=-1, r=d+1;
	int ans=0;
	while(l<r){
		int md=(l+r+1) >> 1;
		ll sum=0;
		for(int i=0;i<d;i++){
			int now = i % (md+1);
			if(now<n){
				sum+=q[n-1-now];
			}
		}
		if(sum < c){
			r=md-1;
		}
		else{
			l=md;
		}
	}
	if(l==d+1){
	cout << "Infinity\n";
	}
	else if(l==-1){
		cout << "Impossible\n";
	}
	else cout << l << endl;
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

