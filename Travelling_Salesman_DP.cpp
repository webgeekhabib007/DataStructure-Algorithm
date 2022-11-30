#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

#define nl "\n"

#ifndef ONLINE_JUDGE
    #include "debug.h"
#else
  #define debug(x...)
#endif

int main(int argc, char const *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
  ll n;cin>>n; 
  vector<vector<ll>> dist(n+2,vector<ll>(n+2));
  for(ll i=0;i<n;i++){
    for(ll j=0;j<n;j++){
      cin>>dist[i][j];
    }
  }
  ll visited = (1<<n) -1;

  vector<vector<ll>> dp((1<<n),vector<ll>(n,-1));


  function<ll(ll,ll)> tsp=[&](ll mark,ll pos)->ll{

    if(mark==visited){      
      return dist[pos][0];
    }
    if(dp[mark][pos]!=-1){
      return dp[mark][pos];
    }
    ll ans = LONG_MAX;
    for(ll city=0;city<n;city++){
      if((mark&(1<<city))==0){
        ll tmp = dist[pos][city] + tsp( mark|(1<<city),city);
        ans = min(ans, tmp);
      }

    }

    return dp[mark][pos] = ans;
  };
    
  ll ans=tsp(1,0);
  cout << "Min cost " << ans << nl;

  for(ll i=0;i<(1<<n);i++){
    for(ll j=0;j<n;j++){
      cout << dp[i][j] << " ";
    }
    cout << nl;
  }
  
  return 0;
} 
