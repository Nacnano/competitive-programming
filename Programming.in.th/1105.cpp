#include<bits/stdc++.h>
using namespace std;

bool hsh[2000010];

int main(){
	
	int n,k;
	scanf("%d%d",&n,&k);
	
	while(n--)
	{
		int x;
		scanf("%d",&x);
		hsh[x]=1;
	}
	
	for(int i=2000000;i>=0;i--)
	{
		if(hsh[i]==1) k--;
		
		if(k==0)
		{
			printf("%d",i);
			break;	
		}
	}
}
