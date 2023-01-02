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


        ll v=5;        
        vector<vector<ll>> g = {
                          {0, 9, 75, 0, 0},
                          {9, 0, 95, 19, 42},
                          {75, 95, 0, 51, 66},
                          {0, 19, 51, 0, 31},
                          {0, 42, 66, 31, 0}
                      };

        ll no_edge=0;
        vector<bool> seleted(v,false);
        seleted[0]=true;

        ll row;
        ll col;

        vector<Node> mst;

        while(no_edge < v-1){
            ll min = LLONG_MAX;
            row=0,col=0;
            for(ll i=0;i<v;i++){
                if(seleted[i]){
                    for(ll j=0;j<v;j++){
                        if(!seleted[j] and g[i][j]){
                            if(min > g[i][j]){
                                min = g[i][j];
                                row=i,col=j;
                            }
                        }
                    }
                }
            }
            //cout << row << " " << col << nl;
            mst.push_back(Node(row,col,g[row][col]));
            seleted[col]=true;
            no_edge++;
        }

        for(auto x: mst){
            cout << x.u << " " << x.v << " " << x.w << nl;
        }
  
  return 0;
} 
