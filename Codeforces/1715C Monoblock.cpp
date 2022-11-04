#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pii pair<int,int>
#define f first
#define s second

const ll p=1e9+7;
const int maxN=100015;
int a[maxN];

void solve(){
	int n, m;
	long long ans=0;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i-1]) ans+=
		else ans +=
		if(a[i]!=a[i-1])
		else ans+= 
	}

	while(m--){
		int x, y;
		cin >> x > y;
		if(a[i]!=a[i-1]) ans+=
		else ans +=
		if(a[i]!=a[i-1])
		else ans+= 
		a[x]
	}
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