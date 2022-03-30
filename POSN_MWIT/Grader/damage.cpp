#include<bits/stdc++.h>
using namespace std;

map<pair<int,int> ,int> mm;

int main(){
	
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int q;
		scanf("%d",&q);
		int x,y,z;
		if(!q)
		{
			scanf("%d%d%d",&x,&y,&z);
			mm[{x,y}]+=z;
		}
		else
		{
			scanf("%d%d",&x,&y);
			printf("%d\n",mm[{x,y}]);
		}
	}
	
}
