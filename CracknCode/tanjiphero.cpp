#include<bits/stdc++.h>
using namespace std;

long long a[305][305];

int main(){
	
	int n;
	scanf("%d",&n);
	
	bool con=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
			if(a[i][j]!=a[1][1]) con=0;
		}
	}
	
	if(con)
	{
		int val=a[1][1];
		long long col=n;
		long long ans=0;
	
		while(n--)
		{
			long long tmp=col/2;
			if(col%2==1) ans+=2*(tmp*tmp+tmp);
			else ans+=2*tmp*tmp;
		}
		printf("%lld",ans*val);
	}
	else if(con==0)
	{
		int row=n,col=n;
		long long ans=0;
		while(col>0)
		{
		
				vector<int> v;
				for(int i=0;i<row;i++)
				{
					if(a[i][col]==1) v.push_back(i);
				}
				vector<int> rev;
				for(int i=row-1;i>=0;i--)
				{
					rev.push_back(v[i]);
				}
				for(int i=row-1;i>=0;i--)
				{
					ans+=abs(rev[i]-v[i]);
				}
				col--;

		
		}
		printf("%lld",ans);
	}

	
}
