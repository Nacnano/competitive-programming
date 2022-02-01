 #include<bits/stdc++.h>
 using namespace std;

 int mm[1010][1010];

 int main(){

    int n,m;
    scanf("%d%d",&n,&m);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        char s[1001];
        scanf("%s",s);
        for(int j=0;j<m;j++)
        {
            if(s[j]=='#') mm[i][j]=0;
            else mm[i][j]=1;

            ans=max(ans,mm[i][j]);
        }
    }

    for(int i =n-2;i>=0;i--)
    {
        for(int j =1;j<m;j++)
        {
            if(mm[i][j])
            {
               mm[i][j] = 1 + min({mm[i+1][j],mm[i][j-1],mm[i+1][j-1]});
            }
            ans = max(ans,mm[i][j]);
        }
    }

    printf("%d",ans);
 }
