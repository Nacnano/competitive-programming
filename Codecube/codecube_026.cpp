#include<bits/stdc++.h>
using namespace std;

int in[1000005],out[1000005];

int main(){
	
	int n;
	scanf("%d",&n);
	
	int mn=1e9,mx=-1;
	while(n--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		in[a]++;
		out[b]++;
		mx=max(mx,b);
		mn=min(mn,a);
	}
	
	int now=0,ans=0;
	for(int i=mn;i<=mx;i++)
	{
		now+=in[i];
		now-=out[i];
		ans=max(ans,now);
	}
	printf("%d",ans);
}
