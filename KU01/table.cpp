#include<bits/stdc++.h>
using namespace std;

int chk[105][105];

bool okay(int x,int y)
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(chk[x+i][y+j]==1) return false;
		}
	}

	return true;
}

int main(){
	ios_base::sync_with_stdio(NULL); cin.tie(NULL);
	
	int l,w,n;
	scanf("%d%d%d",&l,&w,&n);
	
	while(n--)
	{
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		for(int i=a;i<c;i++)
		{
			for(int j=b;j<d;j++)
			{
				chk[j][i]=1;
			}
		}
	}
	
	
	int ans=0;
	for(int i=0;i<=w-3;i++)
	{
		for(int j=0;j<=l-3;j++)
		{
			if(okay(i,j))
			{
				ans++;
			}
		}
	}
	printf("%d",ans);
	
	return 0;
}
