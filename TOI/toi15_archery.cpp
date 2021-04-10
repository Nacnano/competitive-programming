#include<bits/stdc++.h>
using namespace std;

pair<long long,long long> v[500010];
long long c[500010];
long long p[500010];
int main(){
	
	int n;
	scanf("%d",&n);
	
	long long sum=0;
	long long mn=1e18;
	for(int i=0;i<n;i++)
	{
		scanf(" %d",&c[i]);
		mn=min(mn,c[i]);
	}
	
	for(int i=0;i<n;i++)
	{
		scanf(" %d",&p[i]);
		sum+=p[i];
		v[i]={p[i],c[i]};
	}
	
	sort(v,v+n);
	
	for(int i=1;i<n;i++)
	{
		v[i].second+=v[i-1].second;
	}
	
	long long ans=1e18;
	long long hans;
	for(int i=0;i<n;i++)
	{
		long long add=0;
		if(i>0) add=v[i-1].second;
		
		long long h=min(mn,v[i].first);
		long long tmp=add-h*n+sum;
//		printf("\n%lld %lld %lld %lld",add,h,sum,tmp);	
		if(tmp<ans)
		{
			ans=tmp,hans=h;
		}
		else if(tmp==ans && h<hans) hans=h;
	}
//	printf("\n");
	printf("%lld %lld",hans,ans);
}
