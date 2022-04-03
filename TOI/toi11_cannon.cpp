#include<bits/stdc++.h>
using namespace std;

vector<int> c;

main(){
	
	int n,m,k,l;
	scanf("%d%d%d%d",&n,&m,&k,&l);
	
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		c.push_back(x);
	}
	
	while(k--)
	{
		int ans=0;
		int left,right,tmp;
		for(int i=1;i<=m;i++)
		{
			int x;
			cin >> x;
			
			bool con=0;
			
			tmp=lower_bound(c.begin(),c.begin()+n,x-l)-c.begin();
			
			if(i==1)
			{
				left=tmp;
				con=1;
			}
			else if(tmp>left)
			{
				left=tmp;
				con=1;
			}
			
			right=upper_bound(c.begin(),c.begin()+n,x+l)-1-c.begin();
			
			if(con==1)
			ans+=(right-left+1);
			else
			ans+=(right-left);
			
			left=right;
		}
		printf("%d\n",ans);
	}
}