#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pii pair<int,int>
#define f first
#define s second

const int maxN=200005;

void solve(){
	int n, a[maxN];
	map<int, int> mm;
	cin >> n;
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=n-1;i>=0;i--){
		if(mm.find(a[i])==mm.end()){
			mm[a[i]]=1;
		}
		else if (mm[a[i]]==1){
			cout << i+1 << "\n";
			return;
		}
	}
	cout << "0\n";
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