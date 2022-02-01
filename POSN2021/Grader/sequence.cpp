#include<bits/stdc++.h>
using namespace std;

bitset<200000005> mm;
long long pr=2e8+1;

int main(){

    int n;
    scanf("%d",&n);
    long long s,a,b;
    scanf("%lld%lld%lld",&s,&a,&b);
    s%=pr;
    a%=pr;
    b%=pr;
    while(n--)
    {
        s=s*a+b;
        s%=pr;
        if(mm[s]) printf("Yes\n");
        else
        {
            mm[s]=1;
            printf("No\n");
        }
    }
 }
