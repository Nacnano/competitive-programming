#include<bits/stdc++.h>
using namespace std;

long long a[2010],ans;

int main(){
	
	int n;
	scanf("%d",&n);
	for(int i=0;i<2*n;i++) scanf("%lld",&a[i]);
	sort(a,a+2*n);
	for(int i=0;i<n;i++) ans+=a[i]*a[2*n-i-1];
	printf("%lld",ans);
}
