#include<bits/stdc++.h>
using namespace std;

double dist(pair<double,double> p1,pair<double,double> p2)
{
	int x1=p1.first;
	int y1=p1.second;
	int x2=p2.second;
	int y2=p2.first;
	return (double)sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}

//bool cmp(const pair<double,double> a,const pair<double,double> b)
//{
//	return a.first<b.first;
//}

int main(){
	
	int w;
	scanf("%d",&w);
	
	while(w--)
	{
		int n;
		double r,d;
		scanf("%d%lf%lf",&n,&r,&d);
		
		set<pair<double,double> > ss;
		pair<double,double> p[100010];
		for(int i=0;i<n;i++)
		{
			scanf("%lf %lf",&p[i].first,&p[i].second);
		}
		
		sort(p,p+n);
		
		int l=0;
		double mn=1e18;
		
		for(int i=0;i<n;i++)
		{
			while(l<i && p[i].first-p[l].first>=mn)
			{
				ss.erase({p[l].second,p[l].first});
				l++;
			}
			
			for(auto it=ss.lower_bound({p[i].second-mn,p[i].first-mn});it!=ss.end() && (*it).first-p[i].second<=mn;it++)
			{
				mn=min(mn,dist(p[i],*it));
			}
			
			ss.insert({p[i].second,p[i].first});
		}
		
		if(mn-2*r>=d) printf("Y\n");
		else printf("N\n");
	}
}
