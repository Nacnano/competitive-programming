#include<bits/stdc++.h>
using namespace std;

int h[1000010];
int r[1000010],l[1000010];

int main(){
	
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&h[i]);
	
	for(int i=1;i<=n;i++)
	{
		l[i]=i-1;
		while(l[i]>=1 && h[i]>=h[l[i]]) l[i]=l[l[i]];
	}
	
	for(int i=n;i>=1;i--)
	{
		r[i]=i+1;
		while(r[i]<=n && h[i]>=h[r[i]]) r[i]=r[r[i]];
	}
	
	for(int i=1;i<=n;i++) printf("%d ",r[i]-l[i]-1);
}
