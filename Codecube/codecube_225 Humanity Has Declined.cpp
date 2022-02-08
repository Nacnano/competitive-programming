#include<bits/stdc++.h>
using namespace std;

int a[200010], last[200010], have[200010];

int main(){
	ios_base::sync_with_stdio(NULL), cin.tie(NULL);
	
	int n,k,q;
	scanf("%d%d%d",&n,&k,&q);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	
	int cnt=0, it=1, it2;
	for(int i=1;i<=n;i++)
	{
		if(cnt<k)
		for(int j=it;j<=n;j++)
		{
			if(a[j]<=k && !have[a[j]]) cnt++;	
			have[a[j]]++;
			if(cnt==k)
			{
				it2=j;
				break;
			}
		}
		
		if(cnt==k) last[i]=min(it2,n);
		else
		{
			for(int j=i;j<=n;j++) last[j]=INT_MAX;
			break;
		}
		it=it2+1;
		have[a[i]]--;
		if(a[i]<=k && !have[a[i]]) cnt--;
	}
//	for(int i=1;i<=n;i++) printf("%d %d\n",i,last[i]);
	while(q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		if(last[l]!=INT_MAX && last[l]<=r) printf("YES\n");
		else printf("NO\n");
	}
	
}
