#include<bits/stdc++.h>
using namespace std;

int w[610][610];
int dis[610];

int main(){
	
	int n;
	scanf("%d",&n);
	for(int i=1;i<=2*n;i++)
		for(int j=1;j<=2*n;j++) 
			scanf("%d",&w[i][j]);
			
	for(int i=2;i<2*n;i++) dis[i]=1e8;
	
	for(int i=2*n;i>1;i--)
		for(int j=i-1;j>1;j--)
			dis[j]=min(dis[j],dis[i]+w[i][j]);
	
	printf("%d",dis[2]);
}
