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


        ll n,m;
        cin>>n>>m;
        vector<ll>wt(n),profit(n);
        for(ll i=0;i<n;i++){
            cin>>wt[i];
        }
        for(ll i=0;i<n;i++){
            cin>>profit[i];
        }

        debug(wt,profit);
        vector<vector<ll>> dp(n+1,vector<ll>(m+1,0));

        

        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=m;j++){
                if(j < wt[i-1]){
                    dp[i][j]=dp[i-1][j];
                }else{
                    //dp[i][j]=max(wt[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]); // max weight
                    dp[i][j]=max(profit[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]); // max profit
                }
            }
        }
        
        cout << "MAx profit: " << dp[n][m] << nl;

  
  return 0;
} 
