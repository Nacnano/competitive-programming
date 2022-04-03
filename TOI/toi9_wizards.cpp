#include <bits/stdc++.h>
using namespace std;

vector<pair<pair<int,int>,pair<int,int> > > tb(10000000);

int main()
{

    int ax,ay,n;
	scanf("%d%d%d",&ax,&ay,&n);

    vector<vector<int> > x(4),y(4);

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<n;j++) 
        {
        	int xa,ya;
        	scanf("%d%d",&xa,&ya);
        	x[i].push_back(xa);
        	y[i].push_back(ya);
		}
    }

    int mx=0;
    for(int i=0;i<n;i++) 
		for(int j=0;j<n;j++)
	    {
	        pair<int,int> tmp={x[0][i]+x[1][j],y[0][i]+y[1][j]};
	        int idx=(((x[0][i]+x[1][j])*3+y[0][i]+y[1][j])%9999991+9999991)%9999991;
	        int co=0;
	        for(;;)
	        {
	            if(tb[idx]==make_pair(make_pair(0,0),make_pair(0,0))) break;
	            co++;
	            idx++;
	            idx%=9999991;
	        }
	        tb[idx]={tmp,{i,j}};
	        mx=max(mx,co);
	    }

    for(int i=0;i<n;i++) 
		for(int j=0;j< n;j++)
	    {
	        pair<int,int> tmp={ax-x[2][i]-x[3][j],ay-y[2][i]-y[3][j]};
	        int idx=(((ax-x[2][i]-x[3][j])*3+ay-y[2][i]-y[3][j])%9999991+9999991)%9999991;
	        int co=0;
	        for(;;)
	        {
	            if(tb[idx].first==tmp)
	            {
	            	printf("%d %d\n",x[0][tb[idx].second.first],y[0][tb[idx].second.first]);
	            	printf("%d %d\n",x[1][tb[idx].second.second],y[1][tb[idx].second.second]);
	                printf("%d %d\n",x[2][i],y[2][i]);
	                printf("%d %d\n",x[3][j],y[3][j]);
	                return 0;
	            }
	            co++;
	            idx++;
	            if(co>mx) break;
	        }
	    }
}