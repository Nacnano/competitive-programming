#include<bits/stdc++.h>
using namespace std;

int a[1505][1505];

int main(){

    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]);

    for(int i=n-1;i>=0;i--)
    {
        for(int j=n-1;j>=0;j--)
            printf("%d ",a[j][i]);
        printf("\n");
    }
}
