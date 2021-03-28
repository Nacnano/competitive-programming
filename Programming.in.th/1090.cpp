#include<bits/stdc++.h>
using namespace std;

long long hsh[200010];

int main(){
	
	int n;
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++) 
	{
		int x;
		scanf("%d",&x);
		hsh[x]++;
	}
	int a;
	scanf("%d",&a);
	long long ans=0;
	for(int i=0;i<=(a-1)/2;i++)
	{	
		ans+=hsh[i]*hsh[a-i];
	}
	
	if(a%2==0) ans+=hsh[a/2]*(hsh[a/2]-1)/2;
	
	printf("%lld",ans);
	
}
