#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pii pair<int,int>
#define f first
#define s second

const int maxN=100005;

void solve(){
	int n, m, a[maxN], ans=0;
	priority_queue<int> pqmid, pqedge;
	cin >> n >> m;

	for(int i=0;i<m;i++){
		cin >> a[i];
	}
	sort(a,a+m);
	for(int i=1;i<m;i++){
		pqmid.push(a[i]-a[i-1]);
	}
	pqedge.push(a[0]-1);
	pqedge.push(n-a[m-1]);

	int t=0;
	while(!pqmid.empty()){
		int now = pqmid.top();
		cout << now << " ";
		pqmid.pop();
		if(!pqedge.empty()){
			while(!pqedge.empty()){
				if(pqedge.top()>=t){
				pqedge.pop();
				}
				else break;
			}
		}
		if(!pqedge.empty()){
			if(pqedge.top()>=now){
				pqmid.push(now);
				now=pqedge.top();
				ans+=max(now-t, 0);
				pqedge.pop();
				t++;
				continue;
			}
		}

		if(now-2*t>0){
			ans+=max(now-2*t-1, 0);
			t++;
		}
		t++;
	}
	cout << ans << "\n";
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt","w", stdout);
	#endif

	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int q=1;
	cin >> q;
	while(q--){
		solve();
	}
	return 0;
}