#include<bits/stdc++.h>
using namespace std;

long long l[15];
long long a[15];
long long s[10000010];
long long t[15];
long long sum[10000010];
int q[15];

int main(){
	
	int n,m,x;
	scanf("%d",&n);
	scanf("%d",&m);
	scanf("%d",&x);
	
	for(int i=1;i<=n;i++) scanf("%lld",&l[i]);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=m;i++) scanf("%lld",&s[i]), sum[i]=sum[i-1]+s[i];
	for(int i=1;i<=x;i++) scanf("%lld",&t[i]);
	
	for(int i=1;i<=x;i++)
	{
		for(int j=1;j<=n;j++) scanf("%d",&q[j]);
		
		
		long long mx=-1;
		q[n+1]=m;
		for(int j=1;j<=n;j++)
		{
			if(a[j]>l[j]) continue;
			
			long long st=q[j],ed=q[j+1];
			long long md=(st+ed)/2;	
			long long cnt=0;
			long long last=st-1;
			while(st<=ed)
			{
				long long left=st,right=ed;
				while(left<=right)
				{
					
					long long mid=(left+right)/2;
		//			printf("%lld %lld %lld\n",left,mid,right);
					if(sum[mid]-sum[st-1]+a[j]>l[j])
					{
						right=mid-1;
					}
					else
					{
						last=mid;
						left=mid+1;
					}

				}
				
		//		printf("cnt %d %lld\n",j,cnt);
				if(last!=st-1)
				{	
					cnt++;
					st=last+1;	
				}
				else
				{
					cnt=1e9;
					break;
				}
			}
			mx=max(mx,cnt);
			if(cnt==1e9) break;
		}
	//	printf("%lld %lld\n",mx,t[i]);
		if(mx<=t[i]) printf("P\n");
		else printf("F\n");
	}
}
