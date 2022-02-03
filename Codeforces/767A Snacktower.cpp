#include<bits/stdc++.h>
using namespace std;

bool have[100010];

int main(){

    int n;
    scanf("%d",&n);

    int curr=n;
    while(n--)
    {
        int x;
        scanf("%d",&x);
        have[x]=1;
        if(x==curr)
        {
            while(have[x])
            {
                have[x]=0;
                printf("%d ",x);
                x--;
                curr--;
            }
        }
        printf("\n");
    }
}
