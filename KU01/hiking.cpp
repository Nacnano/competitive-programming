#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	
	int n,s;
	scanf("%d%d",&n,&s);
	
	int smn=s, smx=s;
	while(n--)
	{
		int x;
		scanf("%d",&x);
		
		if(x%3==0 && x%4!=0)
		{
			smn-=10*x/3;
			smx-=10*x/3;
		}
		else if(x%3!=0 && x%4==0)
		{
			smn-=10*x/4;
			smx-=10*x/4;
		}
		else if(x%12==0)
		{
			smn-=10*x/3;
			smx-=10*x/4;
		}
	}
	
	printf("%d %d",smn,smx);
	return 0;
}
