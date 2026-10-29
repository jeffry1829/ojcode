#include <bits/stdc++.h>
using namespace std;

const int _n = 2e4 + 10;
const int _logn = log2(2*_n+1) + 1;
int t,n;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        int nn = 2 * n + 1;
        int lst = 0;
        for(int j = _logn;j>=0;j--){
            int candi = lst + (1<<j);
            if(candi <= nn){
                cout<<"? "<<candi<<' ';
                for(int i=1;i<=candi;i++){
                    cout<<i<<' ';
                }
                cout<<endl;
                int res;
                cin>>res;
                if(!((candi - res) & 1)){
                    // does not contain 3 nums
                    lst = candi;
                }
            }
        }
        lst++;

        // ----------------

        int fst = nn + 1;
        for(int j = _logn;j>=0;j--){
            int candi = fst - (1<<j);
            if(candi >= 1){
                cout<<"? "<<nn - candi + 1<<' ';
                for(int i=nn;i>=candi;i--){
                    cout<<i<<' ';
                }
                cout<<endl;
                int res;
                cin>>res;
                if(!((nn - candi + 1 - res) & 1)){
                    // does not contain 3 nums
                    fst = candi;
                }
            }
        }
        fst--;

        // ---------------

        int mid = fst;
        for(int j = _logn;j>=0;j--){
            int candi = mid + (1<<j);
            if(candi <= lst - 1){
                cout<<"? "<<candi - fst + 2<<' '<<fst<<' '<<lst<<' ';
                for(int i=fst+1;i<=candi;i++){
                    cout<<i<<' ';
                }
                cout<<endl;
                int res;
                cin>>res;
                if(!((candi - fst + 2 - res) & 1)){
                    // does not contain 3 nums
                    mid = candi;
                }
            }
        }
        mid++;

        cout<<"! "<<fst<<' '<<mid<<' '<<lst<<endl;
    }

    return 0;
}