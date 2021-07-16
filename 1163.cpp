#include<bits/stdc++.h>
using namespace std;

int n;
int arr[20];

void solve(int lv,int cnt)
{
	if(lv==n+1)
	{
		for(int i=n;i>=1;i--)
			if(!arr[i])
			{
				for(int j=1;j<=n;j++) printf("%d",arr[j]);
				printf(" ");
				for(int j=1;j<=n;j++)
				{
					if(i==j) printf("1");
					else printf("%d",arr[j]);
				}
				printf("\n");
			}
		return;
	}
	arr[lv]=0;
	solve(lv+1,cnt);
	arr[lv]=1;
	solve(lv+1,cnt+1);
} 

int main(){
	scanf("%d",&n);
	solve(1,0);
}
