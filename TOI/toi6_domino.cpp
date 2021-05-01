#include<bits/stdc++.h>
using namespace std;

int n;
int tmp[15];
void solve(int lv,int k)
{
    if(lv==n)
    {
        for(int i=0;i<k;i++)
        {
            if(tmp[i]==1)
            {
                printf("--\n");
            }
            else if(tmp[i]==2)
            {
                printf("||\n");
            }

        }
        printf("E\n");
        return;
    }
    if(lv>n) return;

    tmp[k]=1;
    solve(lv+1,k+1);
    tmp[k]=2;
    solve(lv+2,k+1);
    tmp[k]=0;
}


int main(){

    scanf("%d",&n);
    solve(0,0);
    return 0;
}
