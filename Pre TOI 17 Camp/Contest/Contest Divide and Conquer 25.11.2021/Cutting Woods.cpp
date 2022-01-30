#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int l,q;
	scanf("%d%d",&l,&q);
	
	set<int> ss;
	ss.insert(0);
	ss.insert(l);

	while(q--)
	{
		int c,x;
		scanf("%d%d",&c,&x);
		if(c==1)
		{
			ss.insert(x);
		}
		else
		{
			auto it=ss.upper_bound(x);
			int a=*it;
			it--;
			int b=*it;
			
			printf("%d\n",a-b);
		}
	}
}
