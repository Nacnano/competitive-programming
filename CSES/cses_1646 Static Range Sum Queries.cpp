#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mxn=2e5+10;

ll ft[mxn];
int arr[mxn];

void update(int x,int val){
	for(x;x<=mxn;x+=x&-x) ft[x]+=val;
}

ll query(int x){
	ll ret=0;
	for(x;x>0;x-=x&-x) ret+=ft[x];
	return ret;
}
int main(){
	ios_base::sync_with_stdio(false), cin.tie(0);
	
	int n, q;
	cin >> n >> q;
	for(int i=1;i<=n;i++)
	{
		cin >> arr[i];
		update(i,arr[i]);
	}
	
	while(q--)
	{
		int t=2, a, b;
		cin >> a >> b;
		if(t==2) cout << query(b)-query(a-1) << "\n";
		else 
		{
			update(a,b-arr[a]);
			arr[a]=b;
		}
	}
	return 0;
}
