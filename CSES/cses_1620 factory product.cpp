#include<bits/stdc++.h>
using namespace std;

const int maxN = 2e5+5;

long long a[maxN];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	int n;
	long long t;
	cin >> n >> t;
	for(int i=0;i<n;i++) cin >> a[i];
	
	long long st=0,ed=1e18;
	long long ans;
	while(st<=ed)
	{
		long long md=st+(ed-st)/2, cnt=0;
		for(int i=0;i<n;i++)
		{
			cnt+=(md/a[i]);
			if(cnt>=t) 
			{
				ans=md;
				ed=md-1;
				break;
			}
			
		}
		if(cnt<t) st=md+1;
	}
	cout << ans;
	
	return 0;
}
