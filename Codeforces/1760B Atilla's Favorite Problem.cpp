#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pii pair<int,int>
#define f first
#define s second

const ll p=1e9+7;
const int maxN=110005;

void solve(){
	int n;
	string str;
	cin >> n;
	cin >> str;
	int ans = 0;
	for(int i=0; str[i];i++){
		ans = max(ans, str[i]-'a');
	}
	cout << ans+1 << endl;
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

