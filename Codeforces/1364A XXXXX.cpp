#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        int sum=0,l=-1,r=0;
        for(int i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            if(x%k)
            {
                if(l==-1) l=i;
                r=i;
            }
            sum+=x;
        }
        if(sum%k) printf("%d\n",n);
        else if(l==-1) printf("-1\n");
        else printf("%d\n",n-min(l+1,n-r));
    }
}
