#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

ll pmod(ll a, ll e) {
    ll res = 1;
    ll tmp = a % MOD;
    while(e){
        if(e & 1){
            res = res * tmp % MOD;
        }
        tmp = tmp * tmp % MOD;
        e >>= 1;
    }
    return res;
}
unordered_map<ll,ll> memo;
ll cnt_gcd1(ll x){
    if(x == 1) return 1;
    if(memo.count(x)){
        return memo[x];
    }
    ll srt = sqrt(x);
    ll ans = pmod(2, x-1);
    for(int v=2;v<=srt;v++){
        if(x % v == 0){
            ans = (ans + MOD - cnt_gcd1(x/v)) % MOD;
            if(x / v != v){
                ans = (ans + MOD - cnt_gcd1(v)) % MOD;
            }
        }
    }
    return memo[x] = (ans + MOD - 1) % MOD;
}

signed main(){
    ll x,y;
    cin>>x>>y;
    if(y%x == 0){
        cout<<cnt_gcd1(y/x);
    }else{
        cout<<0<<'\n';
    }
    return 0;
}