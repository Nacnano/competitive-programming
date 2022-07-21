#include<bits/stdc++.h>
using namespace std;
const int maxN = 200005;

void solve(){
	string s;
	int cnt=0, free=0;
	cin >> s;
	for(int i=0;s[i];i++){
		if(s[i]=='(') cnt++;
		else if(s[i]==')') {
			cnt--;
		}
		else if(s[i]=='?'){
			if(cnt==0) cnt++;
			else free++;
		}

		if(cnt<0){
			cnt++;
			free--;
		}
		
		if(cnt==0 && free >2){
			cout << "NO\n";
			return;
		}

		// cout << free << " " << cnt << "\n";
	}
	if(free>2) cout << "NO\n";
	else cout << "YES\n";

}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	ios_base::sync_with_stdio(0), cin.tie(NULL);

	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}