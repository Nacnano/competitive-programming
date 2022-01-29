#include<bits/stdc++.h>
using namespace std;
map<pair<int,int> ,bool> mm;

int main(){
	
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		long long  x,y;
		scanf("%lld%lld",&x,&y);
		mm[{x,y}]=1;
	}
	
	long long ans=0;
	
	for(int i=0;i)

	
	printf("%lld",ans);
	
}
