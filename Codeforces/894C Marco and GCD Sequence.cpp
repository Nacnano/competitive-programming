#include<bits/stdc++.h>
using namespace std;

int a[100010];

int _gcd(int a,int b)
{
    if(a>b) swap(a,b);
    int r=a%b;
    while(r!=0)
    {

        a=b;
        b=r;
        r=a%b;
    }
    return b;
}

int main(){

    int m;
    scanf("%d",&m);

    int mn=INT_MAX;
    for(int i=0;i<m;i++)
    {
        scanf("%d",&a[i]);
        mn=min(mn,a[i]);
    }
    int gcd=a[0];
    for(int i=1;i<m;i++) gcd=_gcd(gcd,a[i]);
    if(mn!=gcd)
    {
        printf("-1");
        return 0;
    }
    else
    {
        printf("%d\n%d ",2*m+1,mn);
        for(int i=0;i<m;i++)
        {
            printf("%d %d ",a[i],mn);
        }
    }
}
