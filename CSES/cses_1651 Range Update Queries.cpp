#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mxn=2e5+5;

ll ft[mxn];
ll arr[mxn];

void update(int pos,ll val){
	for(;pos<=mxn;pos+=pos&-pos) ft[pos]+=val;
}

ll query(int idx){
	ll ret=0;
	for(;idx>0;idx-=idx&-idx) ret+=ft[idx];
	return ret;
}

int main(){
	
	int n, q;
	cin >> n >> q;
	for(int i=1;i<=n;i++)
	{
		cin >> arr[i];
		update(i,arr[i]);
		update(i+1,-arr[i]);
	}
	
	while(q--)
	{
		int t;
		cin >> t;
		if(t==2)
		{
			int x;
			cin >> x;
			cout << query(x) << "\n";
		}
		else
		{
			int a, b;
			ll u;
			cin >> a >> b >> u;
			update(a, u);
			update(b+1, -u);
		}
	}
	return 0;
}
