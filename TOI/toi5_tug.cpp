#include<bits/stdc++.h>
using namespace std;

int a[2010],b[2010];;

int main(){

    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
    }

    sort(a,a+n);
    sort(b,b+n);

    long long sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=abs(a[i]-b[i]);
    }
    printf("%d",sum);
}
