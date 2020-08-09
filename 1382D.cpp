#include <bits/stdc++.h>
using namespace std;
const int _n = 80200;
int t, n, p[_n];
bool dp[2][_n];
vector<int> ans;
main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> t;while (t--) {
    cin >> n; ans.clear(); memset(dp,0,sizeof dp); int tw = n << 1;
    for (int i = 0; i < tw; i++) cin >> p[i];
    int maxx = p[0], prev = 0;
    for (int i = 1; i < tw; i++)if(p[i]>maxx) maxx=p[i],ans.push_back(i-prev),prev=i;
    ans.push_back(tw-prev);
    dp[0][ans[0]]=1,dp[0][0]=1;
    for(int i=1;i<ans.size();i++)for(int j=0;j<=tw;j++){
      if(ans[i]>j)dp[i&1][j]=dp[!(i&1)][j];
      else dp[i&1][j]=dp[!(i&1)][j] | dp[!(i&1)][j-ans[i]];
    }
    if(dp[((int)ans.size()-1)%2][n])cout<<"YES\n";
    else cout<<"NO\n";
  }
  return 0;
}