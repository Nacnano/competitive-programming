#include<bits/stdc++.h>
using namespace std;

int hsh[305];

int main(){

	ios_base::sync_with_stdio(0);
	
	int n;
	scanf("%d",&n);
	
	int ans=0;
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		hsh[x]++;
		ans=max(ans,hsh[x]);
	}
	
	printf("%d",ans);
	return 0;
}
