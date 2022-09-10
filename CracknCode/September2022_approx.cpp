#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pii pair<int,int>
#define f first
#define s second

const int maxN=1e6+5;
int p[maxN];

int _find(int x){
	if(p[x]==x) return x;
	return p[x] = _find(p[x]);
}
void solve(){
	int n, r, q;
	cin >> n >> r >> q;

	for(int i=1;i<=n;i++) p[i]=i;
	while(r--){
		int a, b;
		cin >> a >> b;

		int pa=_find(a), pb=_find(b);
		p[pa]=pb;
	}
	while(q--){
		int a, b;
		cin >> a >> b;
		int pa=_find(a), pb=_find(b);
		cout << (pa==pb ? "Y\n" : "N\n");
	}

}

int main(){
	// #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt","w", stdout);
	// #endif

	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int t=1;
	// cin >> t;
	while(t--){
		solve();
	}
	return 0;
}