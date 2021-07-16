#include<bits/stdc++.h>
using namespace std;

long long pr=1e12+3;
long long chem[100010];
map<long long,int> mm;

int main(){
	int n,p;
	scanf("%d%d",&n,&p);
	for(int i=1;i<=n;i++)
	{
		long long hash=0;
		for(int j=1;j<=p;j++)
		{
			long long x;
			scanf("%lld",&x);
			hash+=x;
			hash*=pr;
		}
		chem[i]=hash;
		mm[hash]=i;
	}
	long long tar=0;
	for(int i=1;i<=p;i++)
	{
		long long x;
		scanf("%lld",&x);
		tar+=x;
		tar*=pr;
	}
	
	for(int i=1;i<=n;i++) 
	if(tar==chem[i])
	{
		printf("%d",i); 
		return 0;
	}
	
	for(int i=1;i<=n;i++)
	{
		long long fnd=tar-chem[i];
		if(fnd==chem[i]) continue;
		if(mm.find(fnd)!=mm.end())
		{
			printf("%d %d",i,mm[fnd]);
			return 0;
		}
	}
	printf("NO");
	return 0;
}
