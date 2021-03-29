#include<bits/stdc++.h>
using namespace std;

int o[100010];

int main(){
	
	int m,u;
	scanf("%d %d",&m,&u);
	
	int mx=-1;
	for(int i=1;i<=u;i++) scanf("%d",&o[i]) , mx=max(mx,o[i]);
	
	int st=mx,ed=1000005;
	while(st<=ed)
	{
		int md=(st+ed)/2;
		
		int cnt=1;
		int sum=0;
		for(int i=1;i<=u;i++)
		{
			sum+=o[i];
			if(sum>md)
			{
				cnt++;
				sum=o[i];
			}
			
		}
		
		if(cnt<=m)
		{
			ed=md-1;
		}
		else
		{
			st=md+1;
		}
	}
	
	printf("%d",st);
}
