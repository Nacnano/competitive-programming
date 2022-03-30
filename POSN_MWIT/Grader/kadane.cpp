#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    scanf("%d",&n);
    scanf("%d",&x);
    int sum=x,st=1,ed=1,kun=1;
    int mx=x;
    for(int i=2;i<=n;i++)
    {
        scanf("%d",&x);
        sum+=x;
        if(x>sum)
        {
            sum=x;
            kun=i;
        }
        if(sum > mx)
        {
            mx=sum;
            st=kun;
            ed=i;
        }
    }

    printf("%d %d\n",st,ed);
    printf("%d",mx);
}
