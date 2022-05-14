#include<bits/stdc++.h>
using namespace std;
const int mxn=2e5+10;

int arr[mxn];
int main(){
	ios_base::sync_with_stdio(false), cin.tie(0);
	
	int n, q;
	cin >> n >> q;
	for(int i=1;i<=n;i++) cin >> arr[i], arr[i]^=arr[i-1];
	while(q--)
	{
		int a, b;
		cin >> a >> b;
		cout << (arr[b]^arr[a-1]) << "\n";
	}
	return 0;
}
