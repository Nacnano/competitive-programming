#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pii pair<int,int>
#define f first
#define s second

const ll p=1e9+7;
const int maxN=110005;
int arr[maxN];
vector<pii> v[maxN];
map<int,bool> done;

void solve(){
	int n, q;
	cin >> n >> q;
	for(int i=1;i<=q;i++){
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({c,i});
		v[b].push_back({c,i});
	}

	for(int i=n;i>=1;i--){
		for(auto x: v[i]){
			if(done[x.s]) continue;
			arr[i]|=x.f;
			done[x.s]=1;
		}
	}

	for(int i=1;i<=n;i++){
		cout << arr[i]<< " ";
	}

}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt","w", stdout);
	#endif

	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int t=1;
	// cin >> t;
	while(t--){
		solve();
	}
	return 0;
}