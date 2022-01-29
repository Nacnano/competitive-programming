#include<bits/stdc++.h>
using namespace std;

int hsh[100010];
int a[100010];
long long ans=0;

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie();
	
	int n,k;
	scanf("%d%d",&n,&k);
	
	int p=0,cnt=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(hsh[a[i]]==0) cnt++;
		hsh[a[i]]++;
		
		if(cnt>=k)
		{
			for(int j=p+1;j<=i;j++)
			{
				hsh[a[j]]--;
				if(hsh[a[j]]==0) cnt--;
				if(cnt<k)
				{
					p=j;
					break;	
				}
			}
		}
		ans+=p;
	}
	printf("%lld",ans);
	return 0;
}
