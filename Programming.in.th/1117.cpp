#include<bits/stdc++.h>
using namespace std;

const int mxn=1e5;
long long a[mxn+5],b[mxn+5],c[mxn+5];

int main(){
	
	int n;
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&a[i],&b[i]);
		c[i]=b[i]-2*a[i];
	}
	
	sort(c+1,c+n+1);
	
	long long ans=0,cnt=n;
	for(int i=n;i>=1;i--)
	{
		if(ans+c[i]-(cnt-1)*(cnt-1) > ans-cnt*cnt)
		{
			ans+=c[i];
			cnt--;
		}
	}
	printf("%lld",ans-cnt*cnt);
}
