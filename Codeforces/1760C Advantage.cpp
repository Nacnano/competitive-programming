#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pii pair<int,int>
#define f first
#define s second

const ll p=1e9+7;
const int maxN=200005;

void solve(){
	int n;
	int a[maxN], b[maxN];
	int mx=0, mx2=0;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i];
		b[i]=a[i];
	}
	sort(b, b+n);
	for(int i=0;i<n;i++){
		if(a[i] != b[n-1]){
			cout << a[i]-b[n-1] << " ";
		}
		else{
			cout << a[i]-b[n-2] << " ";
		}
	}
	cout << endl;

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

