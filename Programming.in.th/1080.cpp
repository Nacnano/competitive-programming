#include<bits/stdc++.h>
using namespace std;

int a[30010];

int main(){
	
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	
	if(n<3) 
	{
		printf("%d",n);
		return 0;
	}
	
	sort(a,a+n);
	int ans=-1;
	for(int i=0;i<n-2;i++)
	{
		int mn=a[i]+a[i+1];
		int it=lower_bound(a+i,a+n,mn)-a;
		ans=max(ans,it-i);
	}
	printf("%d",ans);
}
