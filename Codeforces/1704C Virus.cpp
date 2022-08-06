#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pii pair<int,int>
#define f first
#define s second

const int maxN=100005;

void solve(){
	int n, m, a[maxN], ans;
	priority_queue<int> pq;
	cin >> n >> m;

	for(int i=0;i<m;i++){
		cin >> a[i];
	}
	sort(a,a+m);

	pq.push(n+a[0]-a[m-1]-1);
	for(int i=1;i<m;i++){
		pq.push(a[i]-a[i-1]-1);
	}

	int t=0;
	ans=m;
	while(!pq.empty()){
		int now = pq.top();
		pq.pop();
		if(now==2*t+1){
			ans+=2*t;
			t++;
		}
		else if(now>2*t+1){
			ans+=1+2*t;
			t+=2;
		}
		else{
			ans+=now;
		}
	}
	cout << ans << "\n";
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