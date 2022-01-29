#include<bits/stdc++.h>
using namespace std;
int cnt[15][4005];
int main(){
 	int n,l,x;
 	scanf("%d%d%d",&n,&l,&x);
 	cnt[0][x]=1;	
 	for(int lv=1;lv<=n;lv++)
 	{
 		
 		for(int i=lv%2+1;i<=2*l-1;i+=2)
		{
			cnt[lv][i]=cnt[lv-1][i-1]+cnt[lv-1][i+1];
			
			if(lv%2==1 && i==lv%2+1) cnt[lv][i]+=cnt[lv-1][i-1];
			else if(lv%2==1 && i==2*l-2) cnt[lv][i]+=cnt[lv-1][i+1];
			
		}	
//		for(int i=1;i<=2*l-1;i++) printf("%d ",cnt[lv][i]);
//		printf("\n");
	}
	
	for(int i=n%2+1;i<=2*l-1;i+=2) printf("%d ",cnt[n][i]);
 }
