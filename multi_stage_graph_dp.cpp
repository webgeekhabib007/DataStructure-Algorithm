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

const ll inf =(ll)1e7;

int main(int argc, char const *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

    ll n,m;cin>>n>>m;
    vector<vector<ll> > graph(n,vector<ll>(n,inf));
    for(ll i=0;i<m;i++){
      ll a,b,c;
      cin>>a>>b>>c;
      a--,b--;
      graph[a][b]=c;
    }
    vector<ll> dp(n,inf);
    vector<ll> dest(n);
    dp[n-1]=0;
    dest[n-1]=n-1;
    for(ll i=n-2;i>=0;i--){
      for(ll j=i;j<n;j++){
        if(graph[i][j]==inf)continue;
        ll tmp=min(dp[i],graph[i][j]+dp[j]);
        if(tmp < dp[i]){
          dp[i]=tmp;
          dest[i]=j;
        }
      }
    }

    debug(dp);
    debug(dest);
    vector<ll> path;
    function<void(ll)> printPath = [&](ll src)->void{
      if(src+1 == n){
        path.push_back(n);
        return ;
      }
      path.push_back(src+1LL);
      printPath(dest[src]);
    };

    printPath(0);
    debug(path);

    cout << "Min cost : " << dp[0] << nl;
    cout << "Shortest path : " << nl;
    for(auto x: path){
      cout << x << " ";
    }cout << nl;
  
  return 0;
} 
