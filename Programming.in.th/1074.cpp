#include<bits/stdc++.h>
using namespace std;

char s[105][105];
int qs[105][105];

int main(){

    int n,m;
    scanf("%d%d",&n,&m);

    for(int i=0;i<n;i++)
        scanf("%s",&s[i]);

    bool con=1;
    int x,y,si;
    for(int i=0;i<n && con;i++)
    {
        for(int j=0;j<m && con;j++)
        {
            if(s[i][j]=='x')
            {
                int k=0;
                while(i+k<n && j+k<m && s[i+k][j]=='x' && s[i][j+k]=='x' && s[i+k][j+k]=='x') k++;
                printf("%d %d %d\n",i+1,j+1,k);
                x=j,y=i,si=k;
                con=0;
            }
        }
    }


}
