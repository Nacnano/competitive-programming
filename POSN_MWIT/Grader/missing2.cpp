#include<stdio.h>

int main(){

    int n;
    scanf("%d",&n);

    long long sum=0;
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        sum+=x;
    }
    n--;
    while(n--)
    {
        int x;
        scanf("%d",&x);
        sum-=x;
    }
    printf("%d",sum);
}
