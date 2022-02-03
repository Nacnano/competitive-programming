#include<bits/stdc++.h>
using namespace std;

double t[100010];

int main(){
	
	int n,k;
	scanf("%d%d",&n,&k);
	
	double mn=1e9;
	for(int i=0;i<n;i++)
	{
		scanf("%lf",&t[i]);
		mn=min(t[i],mn);
	}
	
	int cnt=n;
	for(int i=0;i<n;i++)
	{
		if((t[i]-mn)>=t[i]/k) cnt--;
	}
	printf("%d",cnt);

	return 0;
}
