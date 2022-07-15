#include<bits/stdc++.h>
using namespace std;
const int mxn = 200005;
long long n, c, q, l[45], r[45];
pair<long long, long long> node[45];

int _find(long long pos){
	for(int i=1;i<=c;i++){
		if(node[i].first<=pos && pos<=node[i].second) return i;
	}
	return int(c-1);
}


void solve(){
	cin >> n >> c >> q;
	string s;
	cin >> s;
	
	long long len=n;
	for(int i=1;i<=c;i++){
		cin >> l[i] >> r[i];
		node[i] = {len+1,len+r[i]-l[i]+1};
		len+=r[i]-l[i]+1;
	}
	node[0]= {1,n};
	l[0]=1, r[0]=n;
	}

	while(q--)
	{
		long long x;
		cin >> x;
		while(x>n){
			int pos=_find(x);
			long long start=node[pos].first;
			x=l[pos]+x-start;
		}
		cout << s[x-1] << "\n";
	}
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