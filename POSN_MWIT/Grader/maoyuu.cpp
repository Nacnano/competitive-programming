#include<bits/stdc++.h>
using namespace std;

set<int> ss;

int main(){
	
	int n;
	scanf("%d",&n);
	
	while(n--)
	{
		int q;
		scanf("%d",&q);
		if(!q)
		{
			int x;
			scanf("%d",&x);
			ss.insert(x);
		}
		else
		{
			int x,y;
			scanf("%d%d",&x,&y);
			int cnt=0;
			auto it=ss.lower_bound(x);
			
			while(it!=ss.end())
			{
				if(*it>y) break;
				it = ss.erase(it);
				cnt++;
			}
			printf("%d\n",cnt);
		}
	}
	
}
