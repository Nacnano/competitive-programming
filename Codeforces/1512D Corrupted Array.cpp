#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    scanf("%d",&t);
    while(t--)
    {
        int arr[200005];
        int n;
        scanf("%d",&n);
        long long sumb=0,mx1=-1,mx2=-1;
        for(int i=0;i<n+2;i++)
        {
            scanf("%d",&arr[i]);
            sumb+=arr[i];
            if(arr[i]>=mx1)
            {
                mx2=mx1;
                mx1=arr[i];
            }
            else if(arr[i]>=mx2) mx2=arr[i];
        }

        bool yes=0;
        if(sumb-mx1-mx2==mx2)
        {
            yes=1;
            for(int i=0;i<n+2;i++)
            {
                if(arr[i]==mx1)
                {
                    mx1=-1;
                    continue;
                }
                if(arr[i]==mx2)
                {
                    mx2=-1;
                    continue;
                }
                printf("%d ",arr[i]);

            }
        }

        else
        {
            for(int i=0;i<n+2;i++)
            {
                if(arr[i]==mx1) continue;

                if(sumb-arr[i]==2*mx1)
                {
                    yes=1;
                    for(int j=0;j<n+2;j++)
                    {
                        if(arr[j]==mx1)
                        {
                            mx1=-1;
                            continue;
                        }
                        if(i!=j) printf("%d ",arr[j]);
                    }
                    break;
                }
            }
        }
        if(!yes) printf("-1");
        printf("\n");
    }

}
