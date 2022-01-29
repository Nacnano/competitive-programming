#include<bits/stdc++.h>
using namespace std;

vector<int> vx,vy;

int main(){
	ios_base::sync_with_stdio(NULL); cin.tie(NULL);
	
	int n;
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
	{
		int x, y;
		scanf("%d%d",&x,&y);
		int nx=x-y;
		int ny=x+y;
		vx.push_back(nx);
		vy.push_back(ny);
	}
	
	sort(vx.begin(),vx.end());
	sort(vy.begin(),vy.end());
	
	int medx,medy;
	medx=vx[n/2];
	medy=vy[n/2];

	long long ans=0;
	for(int i=0;i<n;i++)
	{
		ans+=abs(vx[i]-medx);
		ans+=abs(vy[i]-medy);
	}
	
	printf("%lld",ans);
	
	return 0;
}
