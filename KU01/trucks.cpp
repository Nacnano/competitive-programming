#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int> > vs;
vector<pair<int,int> > vt;
stack<int> stk;
bool chk[2010];
int main(){
	
	int n,l;
	scanf("%d%d",&n,&l);
	for(int i=1;i<=n;i++)
	{
		int s,t;
		scanf("%d%d",&s,&t);
		vs.push_back({s,i});
		vt.push_back({t,i});
	}
	
	sort(vs.begin(),vs.end());
	sort(vt.begin(),vt.end());
	vs.push_back({INT_MAX,n+1});
	vt.push_back({INT_MAX,n+1});
	
	int it1=0;
	int it2=0;
	int ans=0;
	while(it1<n)
	{
	//	printf("IT1 %d IT2 %d\n",it1,it2);
		if(vs[it1].first<vt[it2].first)
		{
			stk.push(vs[it1].second);
			it1++;
		}
		else if(vs[it1]>=vt[it2] && chk[vt[it2].second]==0)
		{
			while(!stk.empty())
			{
		//		printf("%d TOP %d\n",it1,stk.top());
				chk[stk.top()]=1;
				stk.pop();
			}
			it2++;
			ans++;
		}
		else 
		{
			it2++;
		}
		
	}
	
	if(it2<n) ans++;
	
	printf("%d",ans);
}
