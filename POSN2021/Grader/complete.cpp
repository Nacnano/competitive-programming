#include<bits/stdc++.h>
using namespace std;

bool hsh[255];

int main(){

        char s[2005];
        scanf("%s",s);
        for(int i=0;s[i];i++) hsh[s[i]]=1;

        for(int i='a';i<='z';i++)
            if(!hsh[i])
            {
                printf("NO\n");
                break;
            }
            else if(i=='z') printf("YES\n");

        for(int i='A';i<='Z';i++)
            if(!hsh[i])
            {
                printf("NO\n");
                break;
            }
            else if (i=='Z') printf("YES\n");


        for(int i='0';i<='9';i++)
            if(!hsh[i])
            {
                printf("NO\n");
                break;
            }
            else if (i=='9') printf("YES\n");
}

