#include<bits/stdc++.h>
using namespace std;

int a[2505];

int main(){

    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int sum=0,kun=0;
    int mx=0,st,ed;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
        if(sum>mx)
        {
            mx=sum,ed=i,st=kun;
        }
        else if(sum<0)
        {
            sum=0;
            kun=i+1;
        }
    }

    if(mx==0)
    {
        printf("Empty sequence");
        return 0;
    }

    for(int i=st;i<=ed;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n%d",mx);

}
