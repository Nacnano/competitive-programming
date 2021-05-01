#include<bits/stdc++.h>
using namespace std;

int j[1010],k[1010];
int day[1010][1010],ti[1010][1010];

int main(){

    int m,n;
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;i++) scanf("%d",&j[i]);
    for(int i=1;i<=n;i++) scanf("%d",&k[i]);

    for(int i=1;i<=n;i++)
    {
        if(ti[0][i-1]+j[i]<=m)
        {
            day[0][i]=day[0][i-1];
            ti[0][i]=ti[0][i-1]+j[i];
        }
        else
        {
            day[0][i]=day[0][i-1]+1;
            ti[0][i]=j[i];
        }
    }

    for(int i=1;i<=n;i++)
    {
        if(ti[i-1][0]+k[i]<=m)
        {
            day[i][0]=day[i-1][0];
            ti[i][0]=ti[i-1][0]+k[i];
        }
        else
        {
            day[i][0]=day[i-1][0]+1;
            ti[i][0]=k[i];
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int p=1;p<=n;p++)
        {
            int dayj=day[i][p-1], tij=ti[i][p-1]+j[p];
            if(tij>m)
            {
                dayj++;
                tij=j[p];
            }
            int dayk=day[i-1][p], tik=ti[i-1][p]+k[i];
            if(tik>m)
            {
                dayk++;
                tik=k[i];
            }
            if(dayj<dayk)
            {
                day[i][p]=dayj;
                ti[i][p]=tij;
            }
            else if(dayj>dayk)
            {
                day[i][p]=dayk;
                ti[i][p]=tik;
            }
            else
            {
                if(tij<=tik)
                {
                    day[i][p]=dayj;
                    ti[i][p]=tij;
                }
                else
                {
                    day[i][p]=dayk;
                    ti[i][p]=tik;
                }

            }
        }
    }

    printf("%d\n%d",day[n][n]+1,ti[n][n]);
}
