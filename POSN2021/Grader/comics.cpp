#include<bits/stdc++.h>
using namespace std;

int a[100010];
int main(){

    int n,m;
    scanf("%d%d",&n,&m);

    int sum=0,ans=0,last=0;
    a[0]=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
        while(sum>m && last<i)
        {
            last++;
            sum-=a[last];
        }
        ans=max(ans,i-last);
    }
    printf("%d",ans);
}
