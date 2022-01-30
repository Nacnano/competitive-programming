#include<bits/stdc++.h>
using namespace std;

int n,k;
long long a[200010];

bool chk(long long mid)
{
	int cnt=1;
	long long sum=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]>mid) return 0;
		if(sum+a[i]>mid)
		{
			cnt++;
			sum=a[i];
		}
		else sum+=a[i];
	}
	if(cnt<=k) return 1;
	else return 0;
}

int main(){
	ios_base::sync_with_stdio; cin.tie(NULL);
	
	scanf("%d%d",&n,&k);
	
	for(int i=0;i<n;i++) scanf("%lld",&a[i]);
	
	long long l=0,r=1e18,ans;
	while(l<=r)
	{
		long long mid=l+(r-l)/2;
		if(chk(mid))
		{
			ans=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	printf("%lld",ans);
	
	return 0;
}
