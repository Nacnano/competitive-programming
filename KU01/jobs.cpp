#include<bits/stdc++.h>
using namespace std;

int a[100010];
vector<int> v;

int main(){
	ios_base::sync_with_stdio(NULL); cin.tie(NULL);
	
	int n;
	scanf("%d",&n);
	
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>18) cnt++;
		else v.push_back(a[i]);
		
	}
	
	int cnt2=v.size();
	if(cnt>cnt2) printf("%d",2*cnt-1);
	else if(cnt==cnt2) printf("%d",2*cnt);
	else printf("%d",cnt+cnt2);
	
	return 0;
}
