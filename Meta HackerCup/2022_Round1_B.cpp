#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll prime=1e9+7;

void solve(){
  ll n, q;
  ll ans=0, s2x=0, s2y=0, s1x=0, s1y=0; 
  cin >> n;
  for(ll i=0;i<n;i++){
    ll x, y;
    cin >> x >> y;
    vx.push_back(x);
    vy.push_back(y);
    s2x+=(x*x)%prime;
    s2x%=prime;
    s1x+=x;
    s1x%=prime;

    s2y+=(y*y)%prime;
    s2y%=prime;
    s1y+=y;
    s1y%=prime;
  }

  cin >> q;
  while(q--){
    ll a, b;
    cin >> a >> b;
    ans+=s2x;
    ans%=prime;

    ans-=2*(s1x*a)%prime;
    ans%=prime;

    ans+=n*((a*a)%prime); 
    ans%=prime;

    ans+=s2y;
    ans%=prime;

    ans-=2*(s1y*b)%prime;
    ans%=prime;

    ans+=n*((b*b)%prime);
    ans%=prime;
  }
  cout << (ans+prime)%prime << "\n";

}

int main(void) {
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt","w", stdout);
  #endif

  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

  int t=1;
  cin >> t;
  for(int i=1;i<=t;i++){
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}