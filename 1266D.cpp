#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int _n = 1e5 + 10;

ll n,m;

vector<ll> in[_n], out[_n];
vector<pair<ll,ll>> G[_n];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    queue<int> q;
    for(int i=0;i<m;i++){
        ll u,v,d;
        cin>>u>>v>>d;
        u--,v--;
        G[u].push_back({v, d});
        out[u].push_back(v);
        in[v].push_back(u);
    }
    for(int i=0;i<n;i++){
        if(in[i].size() && out[i].size()){
            q.push(i);
        }
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        while(in[node].size() && out[node].size()){
            
        }
    }
    
    return 0;
}