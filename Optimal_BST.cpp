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
    
    //coding start here...
    
    
    ll n;cin>>n;
    vector<ll>k(n),f(n);
    for(ll i=0;i<n;i++){
        cin>>k[i];
    }
    for(ll i=0;i<n;i++){
        cin>>f[i];
    }
    vector<vector<ll>> cost(n+1,vector<ll>(n+1,0));
    vector<vector<ll>> parent(n+1,vector<ll>(n+1,0));
    for(ll i=0;i<n;i++){
        cost[i][i+1]=f[i];
        parent[i][i+1]=i+1;
    }
    for(ll len=2;len<=n;len++){
        for(ll i=0;i<=n-len;i++){
            ll j=i+len;
            cost[i][j]=INT_MAX;
            ll weight=accumulate(f.begin()+i,f.begin()+j,0LL); // sum of frequency from i+1...j
            for(ll k=i;k<=j;k++){
                ll tmp = cost[i][k-1]+cost[k][j]+weight;
                if(tmp < cost[i][j]){
                    parent[i][j]=k;
                    cost[i][j]=tmp;
                }
            }
        }
    }
    //printing the cost table.
    for(auto x: cost){
        for(auto y: x){
            cout << y << " ";
        }
        cout << nl;
    }
  return 0;
} 
