#include<bits/stdc++.h>
using namespace std;

int a[200010];

int main(){
	
	int n,x;
	cin >> n >> x;
	for(int i=0;i<n;i++) cin >> a[i];
	sort(a,a+n);
	
	int it1=0, it2=n-1, ans=0;
	while(it1<=it2)
	{
 		ans++;
		int sum=0, cnt=0;
		while(sum + a[it2] <= x && cnt<2)
		{
			sum += a[it2];
			it2--;
			cnt++;
		}
		while(sum + a[it1] <= x && cnt<2)
		{
			sum += a[it1];
			it1++;
			cnt++;
		}
	}
	cout << ans;
}
