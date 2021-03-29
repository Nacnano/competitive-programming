#include<bits/stdc++.h>
using namespace std;

bool chk[1000010];

int main(){
	
	int n,m;
	scanf("%d%d",&n,&m);
	
	int cnt=0;
	int dead=0;
	
	while(dead<n)
	{
		for(int i=1;i<=n;i++)
		{
			if(chk[i]) continue;
			cnt++;
			if(cnt==m)
			{
				cnt=0;
				chk[i]=1;
				printf("%d ",i);
				dead++;
			}
		}
		
	}
	
}
