#include<bits/stdc++.h>
using namespace std;
long long arr[200010];

int main(){
	
	int n;
	cin >> n;
	for(int i=0;i<n;i++) cin >> arr[i];
	sort(arr,arr+n);
	
	long long ans=0, md=arr[int(n/2)];
	for(int i=0;i<n;i++) ans+=abs(md-arr[i]);
	cout << ans;
}