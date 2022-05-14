#include<bits/stdc++.h>
using namespace std;
const int mxn=2e5+10;

int st[4*mxn];
int arr[mxn];

void build(int v,int l,int r){
	if(l==r) st[v]=arr[l];
	else
	{
		int mid=(l+r)/2;
		build(2*v, l, mid);
		build(2*v+1, mid+1, r);
		st[v]=min(st[2*v], st[2*v+1]);
	}
}

void update(int v,int l,int r,int pos, int val){
	if(l==r) st[v]=arr[pos];
	else
	{
		int mid=(l+r)/2;
		if(pos<=mid) update(2*v, l, mid, pos, val);
		else update(2*v+1, mid+1, r, pos, val);
		st[v]=min(st[2*v],st[2*v+1]);
	}
}

int query(int v, int tl, int tr, int l, int r){
	if(r<tl || tr<l) return 1e9+10;
	if(l<=tl && tr<=r) return st[v];
	int mid = (tl+tr)/2;
	return min(query(2*v, tl, mid, l, r), query(2*v+1, mid+1, tr, l, r));
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(0);
	
	int n, q;
	cin >> n >> q;
	for(int i=1;i<=n;i++) cin >> arr[i];
	build(1, 1, n);
	
	while(q--)
	{
		int t=2, a, b;
		cin >> a >> b;
		if(t==2) cout << query(1, 1, n, a, b) << "\n";
		else arr[a]=b, update(1, 1, n, a, b);
	}
	return 0;
}
