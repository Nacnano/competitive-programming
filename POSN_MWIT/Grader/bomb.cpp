#include<bits/stdc++.h>
using namespace std;

double x[2010],y[2010];
double dis[2010];
bool vis[2010];
vector<double> v;

double dist(double x1,double y1,double x2,double y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lf %lf",&x[i],&y[i]), dis[i]=FLT_MAX;
	
	dis[1]=0;
	int now=1,next;
	for(int i=1;i<=n-1;i++) 
	{
		double mn=FLT_MAX;
		for(int j=1;j<=n;j++)
		{
			if(vis[j] || j==now) continue;
			dis[j]=min(dis[j],dist(x[now],y[now],x[j],y[j]));
			if(dis[j]<mn)
			{
				mn=dis[j];
				next=j;
			}
		}
		vis[now]=1;
		v.push_back(dis[next]);
		now=next;
	}
	
	sort(v.begin(),v.end());
	printf("%.3lf",v[n-1-m]);
}
