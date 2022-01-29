#include<bits/stdc++.h>
using namespace std;

bool chk[740];

int main(){
	
	ios_base::sync_with_stdio(NULL); cin.tie(NULL);
	
	int n;
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		
		for(int j=0;j<(b-a+360)%360;j++)
		{
			chk[a+j]=1;
		}
	}
	
	int ans=0;
	for(int i=0;i<720;i++)
	{
		if(chk[i]==0) continue; 
		
		int sum=0;
		for(int j=0;j<360;j++)
		{
			if(chk[i+j]==1) sum++;
			else break;
		}
		ans=max(ans,sum);
	}
	printf("%d",ans);
	
	return 0;
}
