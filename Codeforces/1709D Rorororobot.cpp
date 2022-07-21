#include<bits/stdc++.h>
using namespace std;
const int maxN = 200005;
int n, m, arr[maxN];
int st[maxN*4];

void build(int v,int l,int r){
	if(l==r) st[v]=arr[l];
	else
	{
		int mid=(l+r)/2;
		build(2*v, l, mid);
		build(2*v+1, mid+1, r);
		st[v]=max(st[2*v], st[2*v+1]);
	}
}

void update(int v,int l,int r,int pos, int val){
	if(l==r) st[v]=arr[pos];
	else
	{
		int mid=(l+r)/2;
		if(pos<=mid) update(2*v, l, mid, pos, val);
		else update(2*v+1, mid+1, r, pos, val);
		st[v]=max(st[2*v],st[2*v+1]);
	}
}

int query(int v, int tl, int tr, int l, int r){
	if(r<tl || tr<l) return -1e9-10;
	if(l<=tl && tr<=r) return st[v];
	int mid = (tl+tr)/2;
	return max(query(2*v, tl, mid, l, r), query(2*v+1, mid+1, tr, l, r));
}


void solve(){
	cin >> n >> m;
	for(int i=1;i<=m;i++){
		cin >> arr[i];
	}
	build(1, 1, m);

	int q;
	cin >> q;
	while(q--){
		int x1, y1, x2, y2, k;
		cin >> y1 >> x1 >> y2 >> x2 >> k;
		if((x1-x2)%k!=0 || (y1-y2)%k!=0){
			cout << "NO\n";
		}
		else if((x1-x2)%k==0){
			int mx=query(1, 1, m, min(x1, x2), max(x1, x2));
			// cout << mx <<"\n";
			if(y1>mx){
				 cout << "YES\n";
			}
			else{
				int mxx=y1+(n-y1)/k*k;
				if(n-mx>=k){
					cout << "YES\n";
				}
				else if(mx<mxx && mxx<=n){
					cout << "YES\n";
				}
				else cout << "NO\n";

			}
		}
		else cout << "NO\n";


	}

}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	ios_base::sync_with_stdio(0), cin.tie(NULL);

	int t=1;
	// cin >> t;
	while(t--){
		solve();
	}
	return 0;
}