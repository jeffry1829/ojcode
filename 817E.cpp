#include <bits/stdc++.h>
using namespace std;

const int _n = 1e5 + 10;
int q;

struct Node{
    int nxt[2];
    int cnt = 0;
    Node(){
        nxt[0] = nxt[1] = -1;
    }
};
vector<Node> trie;
void add(int x){
    int cur = 0;
    for(int i=30;i>=0;i--){
        int bit = (x>>i) & 1;
        if(trie[cur].nxt[bit] == -1){
            trie[cur].nxt[bit] = trie.size();
            trie.push_back(Node());
        }
        cur = trie[cur].nxt[bit];
        trie[cur].cnt++;
    }
}
void del(int x){
    int cur = 0;
    for(int i=30;i>=0;i--){
        int bit = (x>>i) & 1;
        cur = trie[cur].nxt[bit];
        trie[cur].cnt--;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    trie.push_back(Node());
    cin>>q;
    while(q--){
        int t,p,l;
        cin>>t;
        switch(t){
            case 1:
                cin>>p;
                add(p);
                break;
            case 2:
                cin>>p;
                del(p);
                break;
            case 3:
                cin>>p>>l;
                int ans = 0;
                int cur = 0;
                for(int i=30;i>=0;i--){
                    bool invert = (p>>i) & 1;
                    int bit = ((l>>i) & 1) ^ invert;
                    if((l>>i) & 1){
                        if(trie[cur].nxt[!bit] != -1){
                            ans += trie[trie[cur].nxt[!bit]].cnt;
                        }
                    }
                    cur = trie[cur].nxt[bit];
                    if(cur == -1) {
                        break;
                    }
                }
                cout<<ans<<'\n';
                break;
        }
    }

    return 0;
}