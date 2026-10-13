#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update>;

const int _n = 1e5 + 10;
int n;
map<int,ordered_set<int>> mpadd;
map<int,ordered_set<int>> mpdel;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=0;i<n;i++){
        int a,t,x;
        cin>>a>>t>>x;
        switch(a){
            case 1:
                mpadd[x].insert(t);
                break;
            case 2:
                mpdel[x].insert(t);
                break;
            case 3:
                auto& stadd = mpadd[x];
                auto& stdel = mpdel[x];
                int add = stadd.order_of_key(t+1);
                int del = stdel.order_of_key(t+1);
                cout<<add - del<<'\n';
                break;
        }
    }

    return 0;
}