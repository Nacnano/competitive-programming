#include<bits/stdc++.h>
using namespace std;
bool check[3][100010];
int main(){
	int t;
	scanf("%d",&t);
	for(int c=1;c<=t;c++)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		for(int i=0;i<=k;i++) check[0][i]=0,check[1][i]=0;
		check[1][0]=1;

		for(int i=1;i<=n;i++)
		{
			int x;
			scanf("%d",&x);
			for(int j=k-1;j>=0;j--) check[(i+1)%2][(j+x)%k] |= check[i%2][j];
		}
		
		for(int i=k-1;i>=0;i--)
			if(check[(n-1)%2][i])
			{
				printf("Case #%d: %d\n",c,i);
				break;
			}
	}
}
