#include <bits/stdc++.h>
using namespace std;
 
int main(){
    string S;
    cin >> S;
    int N = S.size();
    
    int ans = 0;
    bool one = false;
    int pt = 0;
    
    while(pt < N)
	{
        if(pt == N-2 && S[pt] == S[pt+1])
		{
            ans++;
            break;
        }
        
        if(one && S[pt] == S[pt-1])
		{
            ans++;
            pt += 2;
            one = false;
        }
		else
		{
            ans++;
            pt++;
            one = true;
        }
    }
    
    cout << ans;
}
