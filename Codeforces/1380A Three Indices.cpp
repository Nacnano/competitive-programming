#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);

        int ans=-1;
        int a,b,c,cnt=0;
        scanf("%d",&a);
        scanf("%d",&b);
        for(int i=2;i<n;i++)
        {
            scanf("%d",&c);
            if(a<b && b>c) ans=i;
            a=b;
            b=c;
        }

        if(ans!=-1) printf("YES\n%d %d %d\n",ans-1,ans,ans+1);
        else printf("NO\n");
    }

}
