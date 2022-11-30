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


        ll n,m;cin>>n>>m;
        vector<ll>v(n);
        for(ll i=0;i<n;i++){
            cin>>v[i];
        }
        //bool dp[n+1][m+1];
        vector<vector<bool> > dp(n+1,vector<bool>(m+1,false));
        //dp[0][0]=true;
        for(ll i=0;i<=n;i++){
            dp[i][0]=true;
        }
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=m;j++){
                if(j< v[i-1]){
                    dp[i][j]=dp[i-1][j];
                }else{
                    dp[i][j]=dp[i-1][j] or dp[i-1][j-v[i-1]];
                }
            }
        }
        vector<ll>sub;
        function<void(ll,ll)> get= [&](ll idx,ll sum)->void{

            //if(dp[idx][sum]==false)return ;
            if(sum <=0)return ;
            if(dp[idx][sum]==true){
                if(dp[idx-1][sum]==true){
                    get(idx-1,sum);
                }else{
                    sub.push_back(v[idx-1]);
                    get(idx-1,sum-v[idx-1]);
                }
                return;
            }else{
                return ;
            }
        };
        get(n,m);

        for(auto x: dp){
            for(auto y: x){
                cout << y << " ";
            }
            cout << nl;
        }
        debug(sub);
        cout << "Subset: " << nl;
        for(auto x: sub){
            cout << x << " ";
        }

  
  return 0;
}
