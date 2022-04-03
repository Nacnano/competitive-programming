#include <bits/stdc++.h>
using namespace std;

int x[15010];
int y[15010];
int a[15010];
vector<int> ans;

main(){

    int n,k;
    scanf("%d%d",&n,&k);

    for(int i=0;i<n;i++)
    {
    	scanf("%d%d",&x[i],&y[i]);
	}
	
	for(int i=0;i<=n;i++) a[i]=INT_MAX;
	int p=0;
	a[p]=-1;
	
	for(;;)
	{
		int mn=INT_MAX;
		int idx;
		int co=0;
		for(int i=0;i<n;i++)
		{
			if(a[i]==-1) continue;
			
			a[i]=min(a[i],abs(x[p]-x[i])+abs(y[p]-y[i]));
			
			if(a[i]<mn)
			{
				mn=a[i];
				co=1;
				idx=i;
			}
		}
		
		if(co==0) break;
		p=idx;
		a[idx]=-1;
		ans.push_back(mn);

	}
	
	sort(ans.begin(),ans.end());
	
	int sum=0;
	for(int i=0;i<n-k;i++) sum+=ans[i];
	
	printf("%d",sum);
	
}