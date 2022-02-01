#include<bits/stdc++.h>
using namespace std;

int a[100005];
int t[100005];

int main(){

    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<n;i++) scanf("%d",&t[i]);

    int use=0;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        if(t[i])
        {
            sum+=a[i];
            a[i]=0;
        }
    }

    for(int i=0;i<k;i++) use+=a[i];

    int mx=use;
    for(int i=k;i<n;i++)
    {

        use+=a[i];
        use-=a[i-k];
        mx=max(mx,use);
    }
    printf("%d",sum+mx);


}
