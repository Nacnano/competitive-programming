#include<bits/stdc++.h>
using namespace std;

int e[15];
int main(){
	ios_base::sync_with_stdio(NULL), cin.tie(NULL);
	
	int v,num,mn=1e9;
	scanf("%d",&v);
	scanf("%d",&e[0]);
	for(int i=1;i<10;i++)
	{
		scanf("%d",&e[i]);
		if(e[i]<=mn)
		{
			mn=e[i];
			num=i;
		}
	}
	
	if(mn>v) printf("-1");
	else if(mn<=e[0])
	{
		int it, mx;
		while(v>=mn)
		{
			mx=-1e9;
			for(int i=9;i>=0;i--)
			{
				if(v-e[i]<0) continue;
				if((v-e[i])/mn>mx)
				{
					mx=(v-e[i])/mn;
					it=i;
				}
			}
			printf("%d",it);
			v-=e[it];
		}
	}
	else
	{
		int it, mx=-1e9;
		mn=e[0];
		for(int i=9;i>0;i--)
		{
			if((v-e[i])/mn>mx)
			{
				mx=(v-e[i])/mn;
				it=i;
			}
		}
		printf("%d",it);
		v-=e[it];
		
		while(v>=mn)
		{
			mx=-1e9;
			for(int i=9;i>=0;i--)
			{
				if(v-e[i]<0) continue;
				if((v-e[i])/mn>mx)
				{
					mx=(v-e[i])/mn;
					it=i;
				}
			}
			printf("%d",it);
			v-=e[it];
		}
	}
	
}
