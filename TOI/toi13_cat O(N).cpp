#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int n;
	scanf("%d",&n);
	
	int prev=0;
	int ans=0;
	while(n--)
	{
		int c;
		scanf("%d",&c);
		
		if(c<=ans) continue;
		else if(!prev) prev=c;
		else
		{
			if(c==prev) prev=0;
			else if(c<prev) ans=max(ans,c);
			else
			{
				ans=max(ans,prev);
				prev=c;
			}
		}
	}
	
	printf("%d",ans);
}
