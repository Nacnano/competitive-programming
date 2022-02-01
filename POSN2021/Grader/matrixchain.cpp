#include<bits/stdc++.h>
using namespace std;

int mcm[15][15];
int it[15][15];
int mat[15];

void print(int i,int j)
{
    if(i==j)
    {
        printf("A%d",i);
        return;
    }
    printf("(");
    print(i,it[i][j]);
    printf(" x ");
    print(it[i][j]+1,j);
    printf(")");
}

int main(){

    int n;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int tmp;
        scanf("%d%d",&mat[i],&tmp);
    }
    int tmp;
    scanf("%d%d",&mat[n-1],&mat[n]);

    for(int i=0;i<=n;i++) mcm[i][i]=0;
    for(int l=1;l<=n;l++)
    {
        for(int i=1;i+l<=n;i++)
        {
            int j=i+l;
            mcm[i][j]=INT_MAX;
            for(int k=i;k<j;k++)
            {
                int val=mcm[i][k]+mcm[k+1][j] + mat[i-1]*mat[k]*mat[j];
                if(mcm[i][j] > val)
                {
                    mcm[i][j] = val;
                    it[i][j]=k;
                }
            }
        }
    }
    printf("%d\n",mcm[1][n]);
    print(1,n);
}
