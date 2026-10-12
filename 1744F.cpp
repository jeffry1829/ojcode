#include <bits/stdc++.h>
using namespace std;

const int _n = 2e5 + 10;
int t,n,p[_n];
pair<int,int> dp[_n];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    unordered_map<int,int> mp;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>p[i];
            mp[p[i]] = i;
        }
        int minl = mp[0];
        int maxr = mp[0];
        dp[0] = {minl,maxr};
        for(int x=1;x<n;x++){
            minl = min(minl, mp[x]);
            maxr = max(maxr, mp[x]);
            dp[x] = {minl,maxr};
        }
        long long ans = 0;
        for(int len=1;len<=n;len++){
            if(len == n) {
                ans++;
                break;
            }
            auto [minn, maxx] = dp[len-1];
            int curlen = maxx - minn + 1;
            int maxlen = len * 2;
            int exclen = maxlen - curlen;
            if(exclen < 0) continue;
            int nxtidx = mp[len];
            int lbound, rbound;
            if(nxtidx < maxx && nxtidx > minn) continue;
            if(nxtidx > maxx){
                lbound = max(0, minn - exclen);
                rbound = min(maxx + exclen, nxtidx - 1);
            }else if(nxtidx < minn){
                lbound = max(minn - exclen, nxtidx + 1);
                rbound = min(n-1, maxx + exclen);
            }
            // int minlen2bound = min(minn - lbound, rbound - maxx);
            // int maxlen2bound = max(minn - lbound, rbound - maxx);
            int a = minn - lbound;
            int b = rbound - maxx;
            ans += 1ll * (a + 1) * (b + 1);
            if(a + b - exclen > 0){
                ans -= 1ll * (a + b - exclen + 1) * (a + b - exclen) / 2ll;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}