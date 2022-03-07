#include<bits/stdc++.h>
using namespace std;

map<int,int> mm;
int a[200010];

int main(){
	
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		mm[a[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		if(mm[m-a[i]]!=i && mm[m-a[i]]!=0)
		{
			printf("%d %d",mm[m-a[i]],i);
			return 0;
		}
	}
	printf("IMPOSSIBLE");
}
