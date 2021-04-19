#include<bits/stdc++.h>
using namespace std;

int main(){

    int q;
    scanf("%d",&q);
    while(q--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        int chk=n-k+1;
        bool win=0;
        int cnt=0;
        while(chk!=0)
        {
            cnt+=chk%2;
            chk/=2;
        }
        if(cnt==1 || n==k) printf("B\n");
        else printf("A\n");
    }
}
