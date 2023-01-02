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


class Node{
public:
    ll u,v,w;
    Node(ll u,ll v,ll w):u(u),v(v),w(w){}
};

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

        #define INF (ll)1e9

        ll v = 4;
    vector<vector<ll> > graph
        = { { 0, 3, INF, 7 },
            { 8, 0, 2, INF },
            { 5, INF, 0, 1 },
            { 2, INF, INF, 0 } };


    vector<vector<ll>> dis(v,vector<ll>(v,INF));
    vector<vector<ll>> next(v,vector<ll>(v,-1));

    for(ll i=0;i<v;i++){
        for(ll j=0;j<v;j++){
            dis[i][j]=graph[i][j];
            

            if(graph[i][j]!=INF){
                next[i][j]=j;
            }
        }
    }

    for(ll k=0;k<v;k++){
        for(ll i=0;i<v;i++){
            for(ll j=0;j<v;j++){
                if(dis[i][k]==INF or dis[k][j]==INF)continue;

                if(dis[i][j] > dis[i][k]+dis[k][j]){
                    dis[i][j] = dis[i][k]+dis[k][j];
                    next[i][j]=next[i][k];
                }
            }
        }
    }

    function<vector<ll>(ll,ll)> constructPath=[&](ll u,ll v)->vector<ll>{
        if (next[u][v] == -1)
            return {};
     
        vector<ll> path = { u };
        while (u != v) {
            u = next[u][v];
            path.push_back(u);
        }
        return path;
    };
    debug(next,dis);
    vector<ll> path = constructPath(1,3);
    for(auto x: path){
        cout << x << " ";
    }
  
  return 0;
} 
