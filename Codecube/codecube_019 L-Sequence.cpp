#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int> > v;
int a[1010];

int main(){
	
	int n,k;
	scanf("%d%d",&n,&k);
	
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	
	while(k--)
	{
		for(int i=2;i<=n;i++)
		{
			if(a[i-1]>a[i])
			{
				for(int j=i-1;j<=n;j++) a[j]=a[j+1];
				break;
			}
		}
		n--;
	}
	
	for(int i=1;i<=n;i++) printf("%d ",a[i]);
	return 0;

}
