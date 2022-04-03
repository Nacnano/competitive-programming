#include<bits/stdc++.h>
using namespace std;
long long a[2010][2010],b[2010][2010];
long long qs1[2010][2010],qsb[2010][2010],qs2[2010][2010],qs3[2010][2010];
 
int main(){
	
	int m,n,k;
	scanf("%d%d%d",&m,&n,&k);
	
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",&a[i][j]);
		}
	}
	
	for(int i=1;i<=m;i++) for(int j=1;j<=n;j++) qs1[i][j]=qs1[i][j-1]+qs1[i-1][j]-qs1[i-1][j-1]+a[i][j];
	for(int i=1;i<=m;i++) for(int j=1;j<=n;j++) qs2[i][j]=qs2[i-1][j-1]+qs1[i][j]-qs1[i-1][j];
	
	long long ans=-1e18;
	
	for(int i=0;i+k<=m;i++)
	{
		for(int j=0;j+k<=n;j++)
		{
			long long area=qs2[i+k][j+k]-qs2[i][j]-(qs1[i+k][j]-qs1[i][j]);
			
			ans=max(area,ans);
		}
	}
	
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			b[i][j]=a[i][n-j+1];
		}
	}
	
	for(int i=1;i<=m;i++) for(int j=1;j<=n;j++) qsb[i][j]=qsb[i-1][j]+qsb[i][j-1]-qsb[i-1][j-1]+b[i][j];
	for(int i=1;i<=m;i++) for(int j=1;j<=n;j++) qs3[i][j]=qs3[i-1][j-1]+qsb[i][j]-qsb[i-1][j];
	
	for(int i=0;i+k<=m;i++)
	{
		for(int j=0;j+k<=n;j++)
		{
			long long area=qs3[i+k][j+k]-qs3[i][j]-(qsb[i+k][j]-qsb[i][j]);
			
			ans=max(area,ans);
		}
	}
	
	printf("%lld",ans);
	return 0;
}
