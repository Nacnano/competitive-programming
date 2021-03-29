#include<bits/stdc++.h>
using namespace std;

bool p[8000010];
vector<int> lp;

int main(){
	
	int mx=8e6;
	
	for(int i=2;i<=mx;i++)
	{
		if(p[i]==0)
		{
			p[i]=1;
			lp.push_back(i);
		}
		
		for(int j=0;j<(int)lp.size() && lp[j]*i<=mx;j++)
		{
			p[lp[j]*i]=1;
		}
	}
	
	
	int n;
	scanf("%d",&n);
	
	printf("%d",lp[n-1]);
}
