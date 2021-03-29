#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int q=5;	
	while(q--)
	{
		int arr1[200010];
		int arr2[200010];
		vector<pair<int,int> > v1;
		vector<pair<int,int> > v2;
		
		int n;
		scanf("%d",&n);
		
		for(int i=0;i<2*n-2;i++)
		{
			scanf("%d",&arr1[i]);			
			if(i%2)
			{
				v1.push_back({arr1[i],arr1[i-1]});
				v1.push_back({arr1[i-1],arr1[i]});
			}			
		}
		
		for(int i=0;i<2*n-2;i++)
		{
			scanf("%d",&arr2[i]);
			
			if(i%2)
			{
				v2.push_back({arr2[i],arr2[i-1]});
				v2.push_back({arr2[i-1],arr2[i]});
			}
		}		
		sort(v1.begin(),v1.end());
		sort(v2.begin(),v2.end());
	
		if(v1==v2) printf("Y");
		else printf("N");	
	}
}






/*
9
2 4 9 4 6 4 1 4 1 5 3 5 7 5 7 8
1 4 4 9 1 5 6 4 3 5 7 5 7 8 2 4
9
2 4 9 4 6 4 1 4 1 5 3 5 7 5 7 8
1 4 9 4 1 5 2 4 6 4 3 5 7 5 7 8
9
2 4 6 4 1 4 1 5 9 4 3 5 7 5 7 8 
1 4 9 4 1 5 2 4 6 4 3 5 7 5 7 8
9
9 4 3 5 7 5 7 8 2 4 6 4 1 4 1 5
1 4 9 4 1 5 2 4 6 4 3 5 7 5 7 8
4
1 2 2 3 3 4 
1 2 1 3 1 4
*/
