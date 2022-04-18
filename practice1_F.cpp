/*
	Yeah, I did misunderstand the problem...
*/

#include<bits/stdc++.h>
using namespace std;

long long a[100005];

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	
	long long n, k;
	cin >> n >> k;
	for(int i=0;i<n;i++) cin >> a[i];
	
	long long l=0, r=1e9;
	while(l<r)
	{
		long long md=l+(r-l)/2, sum=0;
		for(int i=0;i<n;i++) sum+=a[i]/md;
		if(sum<=k) r=md;
		else l=md+1;
		cout << l << " " << r << " " << sum <<"\n";
	}
//	r=1e9;
//	while(l<r)
//	{
//		long long md=l+(r-l)/2, sum=0;
//	}
//	cout << l;
}
