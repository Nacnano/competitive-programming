#include<bits/stdc++.h>
using namespace std;

long long x[100010];
vector<long long> v;

int main(){
	ios_base::sync_with_stdio(NULL); cin.tie(NULL);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",&x[i]);
		v.push_back(x[i]);
	}
	
	int it=0;
	int last=1;
	int ans=0;
	int now=1;
	int i=1;
	for(;i<=k;i++)
	{
		if(it>=v.size()) break;
		long long a;
		int col;
		scanf("%lld%d",&a,&col);
		
		
		
		if(a<v[it+1])
		{
			last=a;
			if(col!=now) ans++;
			now=col;
		}
		else
		{
			if(1)
			{
				if(now!=it%2) ans++;
				ans++;
				now=1-now;
				it++;
				last=v[it];
			}
		}
	}
	
	int colper=v.size()+1;
	colper%=2;
	for(;i<=k;i++)
	{
		long long a;
		int col;
		scanf("%lld%d",&a,&col);
		
		if(1)
		{
			if(now!=colper) ans++;
			if(colper!=col) ans++;
			last=a;
			now=col;
		}
		
	}
	
	printf("%d",ans);
	
	return 0;
}
