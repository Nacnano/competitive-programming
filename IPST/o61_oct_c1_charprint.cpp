#include<bits/stdc++.h>
using namespace std;

const int mxn=300010;
long long ft[mxn];
string a,b;
int mode;
priority_queue<long long, vector<long long>, greater<long long> > pq[30];

void update(int x)
{
	for(;x<mxn;x+=x&-x)
		ft[x]++;
}

long long query(int x)
{
	long long ret=0;
	for(;x>0;x-=x&-x)
	ret+=ft[x];
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	cin >> mode >> a >> b;
	for(int i=0;a[i];i++) pq[a[i]-'a'].push(i+1);
	
	long long sol1=0 ,sol2=0;
	for(auto tmp:b)
	{
		if(pq[tmp-'a'].empty())
		{
			cout << "-1";
			return 0;
		}
		int val=pq[tmp-'a'].top();
		pq[tmp-'a'].pop();
		sol1+=val;
		sol2+=query(val);
		update(val);	
	}
	
	long long ans=sol1-mode*sol2;
	cout << ans;
	return 0;

}
