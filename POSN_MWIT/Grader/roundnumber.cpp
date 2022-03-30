#include<bits/stdc++.h>
using namespace std;

int main(){

    int a,k;
    scanf("%d%d",&a,&k);
    int mul=1;
    for(int i=0;i<k;i++) mul*=10;

    int tmp=a%mul;
    double chk=(double)tmp/mul;
    if(chk>=0.5) printf("%d",(a/mul)*mul+mul);
    else printf("%d",(a/mul)*mul);
}
