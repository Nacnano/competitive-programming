#include<bits/stdc++.h>
using namespace std;

long long row[310];

int main(){
	
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		int pos;
		scanf("%d",&pos);
		
		row[pos]++;
		bool con=1;
		for(int j=1;j<=k;j++)
		{
			if(row[j]<=0)
			{
				con=0;
				break;
			}
		}
		
		if(con)
		{
			long long cnt=k;
			for(int j=1;j<=k;j++)
			{
				if(cnt<=row[j])
				{
					row[j]-=cnt;
					cnt=0;
					break;
				}
				else
				{
					cnt-=row[j];
					row[j]=0;
				}
			}
		}
	}
	
	long long ans=0;
	for(int i=1;i<=k;i++)
	{
		ans+=row[i];
	}

	printf("%lld",ans);
}
