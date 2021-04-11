#include<bits/stdc++.h>
using namespace std;

map <int, vector<int> > v;

int main(){
	
	int n,q;
	scanf("%d%d",&n,&q);
	
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		v[x].push_back(i);
	}
	
	while(q--)
	{
		int l,r,c;
		scanf("%d%d%d",&l,&r,&c);
		
		auto itl=lower_bound(v[c].begin(),v[c].end(),l);
		auto itr=upper_bound(v[c].begin(),v[c].end(),r);
		printf("%d\n",itr-itl);
	}
}
