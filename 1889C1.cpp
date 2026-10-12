#include <bits/stdc++.h>
using namespace std;

const int _n = 2e5 + 10;
int t,n,m,k;
vector<tuple<int,int,int>> rains; // idx, is_r?, day 

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        rains.clear();
        for(int i=0;i<m;i++){
            int l,r;
            cin>>l>>r;
            l--;
            rains.push_back({l, 0, i});
            rains.push_back({r, 1, i});
        }
        sort(rains.begin(),rains.end());

        set<int> cur_days;
        map<pair<int,int>,int> cnt; // [day,day] -> cnt , day=-1 for no day
        int idx = 0;
        for(int i=0;i<n;i++){
            while(idx < rains.size()){
                auto [curid, is_r, day] = rains[idx];
                if(curid > i) break;
                if(!is_r){
                    cur_days.insert(day);
                }else{
                    cur_days.erase(day);
                }
                idx++;
            }
            if(cur_days.size() == 0){
                cnt[{-1,-1}]++;
            }else if(cur_days.size() == 1){
                cnt[{*cur_days.begin(), -1}]++;
            }else if(cur_days.size() == 2){
                cnt[{*cur_days.begin(), *(++cur_days.begin())}]++;
            }
        }
        auto it = cnt.begin();
        int maxx = 0;
        while(it != cnt.end()){
            if(it->first != make_pair<int,int>(-1,-1)){
                auto [d1,d2] = it->first;
                if(d2 != -1){
                    maxx = max(maxx, cnt[{d1,d2}] + cnt[{d1,-1}] + cnt[{d2, -1}]);
                }else{
                    maxx = max(maxx, cnt[{d1,d2}]);
                }
            }
            it++;
        }
        priority_queue<int> pq;
        it = cnt.begin();
        while(it!=cnt.end()){
            if(it->first.second == -1){
                auto [d1,d2] = it->first;
                if(d1 != -1){
                    pq.push(cnt[{d1,d2}]);
                }
            }
            it++;
        }
        if(pq.size() >= 2){
            int max1 = pq.top();
            pq.pop();
            int max2 = pq.top();
            pq.pop();
            maxx = max(maxx, max1+max2);
        }

        cout<<maxx + cnt[{-1,-1}]<<'\n';
    }

    return 0;
}