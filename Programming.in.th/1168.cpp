#include<bits/stdc++.h>
using namespace std;

vector<int> seq;
void gen(int last,int val)
{
	val=val*10+last;
	seq.push_back(val);
	if(val%10==9) return;
	for(int i=last+1;i<=9;i++) gen(i,val);
}

int main(){
	gen(0,0);
	int t;
	scanf("%d",&t);
	sort(seq.begin(),seq.end());
	while(t--)
	{
		long long x;
		scanf("%lld",&x);
		if(x>=seq.size()) printf("-1\n");
		else printf("%d\n",seq[x]);
	}
}
