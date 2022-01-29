#include<bits/stdc++.h>
using namespace std;

int chk[200010];

int main(){
	ios_base::sync_with_stdio(NULL); cin.tie(NULL);
	
	int n,k,t;
	scanf("%d%d%d",&n,&k,&t);
	
	chk[1]=1;
	int ans=1;
	int now=1+k;
	while(now!=1)
	{
	//	printf("now %d\n",now);
		if(!chk[now] && now!=t)
		{
			chk[now]=1;
			ans++;
		}
		
		if(now==t)
		{
			ans++;
			break;
		}
		now+=k;
		now%=n;
		
	}
	
	printf("%d",ans);
	
	
	return 0;
}
