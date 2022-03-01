#include<bits/stdc++.h>
using namespace std;

int a[1000010];
int main(){
	
	int n,k,p,l=1e9;
	scanf("%d%d%d",&n,&k,&p);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]), l=min(l,a[i]);
	
	int r=1e9, ans;
	while(l<=r)
	{
		int md=(l+r)/2, chk=1, i, cnt=0;
		for(i=1;i<=n;i++)
		{
			if(cnt==k) break;
			if(a[i]>md)
			{
				cnt++;
				i+=p-1;
			}
		}
		for(;i<=n;i++) if(a[i]>md) chk=0;
		
		if(chk==0) l=md+1;
		else
		{
			ans=md;
			r=md-1;
		}
	}
	printf("%d",ans);
	
}
