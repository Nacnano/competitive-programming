#include<bits/stdc++.h>
using namespace std;

main(){
	
	int q=20;
	while(q--)
	{
		int n,m;
		scanf("%d%d",&m,&n);
		if(2*n>m)printf("0\n");
		else
		{
			int ans=(4*n-m)/2+1;
			if(ans>0)
				printf("%d\n",ans);
			else
				printf("0\n");
		}

	}
}