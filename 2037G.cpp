#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll _n = 2e5 + 10,_n2 = 1e6+10;
const ll mod = 998244353;
ll n,a[_n];
bool not_prime[_n2];
ll dp[_n2];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    not_prime[1] = 1;
    for(int i=2;i * i<_n2;i++){
        if(!not_prime[i]){
            for(int j = i * i;j<_n2;j+=i){
                not_prime[j] = 1;
            }
        }
    }

    ll n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ll cnt = 0;
    for(int i=n-1;i>=0;i--){
        vector<int> prime_factors;
        for(int j=1;j * j<=a[i];j++){
            if(a[i] % j == 0){
                if(!not_prime[j]){
                    prime_factors.push_back(j);
                }
                if(a[i] / j != j && !not_prime[a[i] / j]){
                    prime_factors.push_back(a[i] / j);
                }
            }
        }
        // sort(prime_factors.begin(),prime_factors.end());
        int pfslen = prime_factors.size();
        int maxbits = (1<<pfslen);
        cnt = 0;
        for(int j=1;j<maxbits;j++){
            ll tmp = 1;
            for(int k=0;k<pfslen;k++){
                if((1<<k) & j){
                    tmp *= prime_factors[k];
                }
            }
            int popcnt = __builtin_popcount(j);
            if(popcnt & 1){
                cnt = (cnt + dp[tmp]) % mod;
            } else {
                cnt = (cnt + mod - dp[tmp]) % mod;
            }
        }
        for(int j=1;j<maxbits;j++){
            ll tmp = 1;
            for(int k=0;k<pfslen;k++){
                if((1<<k) & j){
                    tmp *= prime_factors[k];
                }
            }
            if(i == n-1){
                dp[tmp] = 1;
            }else{
                dp[tmp] = (dp[tmp] + cnt) % mod;
            }
        }
    }
    cout<<cnt<<'\n';

    return 0;
}