#include<bits/stdc++.h>
using namespace std;

int x[100010], y[100010];
int hshx[100010], hshy[100010];

int main(){
	ios_base::sync_with_stdio(NULL); cin.tie(NULL);
	
	int l,w,n,m,q;
	scanf("%d%d%d%d%d",&l,&w,&n,&m,&q);
	
	x[0]=0;
	x[n+1]=l;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x[i]);
		if(x[i]-x[i-1]<=100000) hshx[x[i]-x[i-1]]++; 
	}
	if(x[n+1]-x[n]<=100000) hshx[x[n+1]-x[n]]++;
	
	y[0]=0;
	y[m+1]=w;
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&y[i]);
		if(y[i]-y[i-1]<=100000) hshy[y[i]-y[i-1]]++; 
	}
	if(y[m+1]-y[m]<=100000) hshy[y[m+1]-y[m]]++;
	
	while(q--)
	{
		long long a;
		scanf("%lld",&a);
		
		long long ans=0;
		for(int i=1;i*i<=a;i++)
		{
			if(a%i) continue;
			
			if(i*i==a)
			{
				ans+=hshy[i]*hshx[i];
				continue;
			}
			ans+=hshy[i]*hshx[a/i];
			ans+=hshx[i]*hshy[a/i];
		}
		printf("%lld\n",ans);
	}

	return 0;
}
