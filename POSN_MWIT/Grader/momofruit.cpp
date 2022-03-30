#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    scanf("%d",&n);
    int sum=0,ans=0;
    while(n--)
    {
        int x;
        scanf("%d",&x);
        if(sum+x<=0)
        {
            sum=x;
            ans++;
        }
        else sum+=x;

        printf("ans %d %d\n",ans,sum);
    }

    if(sum>0) ans++;
    printf("%d",ans);
}


