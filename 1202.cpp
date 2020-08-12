#include<bits/stdc++.h>
#define ll int
using namespace std;
struct b{
	ll pos,H,type;
	bool operator<(const b& rhs){
		if(pos!=rhs.pos) return pos<rhs.pos;
		if(H!=rhs.H) return H<rhs.H;
		else return type<rhs.type;
	}
};
vector<b> bs;
multiset<ll,greater<ll> > ms;
main(void){
	ll n,L,H,R;
	while(scanf("%d",&n)==1 && n){
		bs.clear(); ms.clear();
		for(ll i=0;i<n;i++){
			scanf("%d%d%d",&L,&H,&R);
			bs.push_back((b){L,H,1});
			bs.push_back((b){R,H,2});
		}
		sort(bs.begin(),bs.end());
		ll now=0;
		ms.insert(0);
		for(int i=0;i<bs.size();){
			int i2=i;
			while(i2<bs.size()&&bs[i].pos==bs[i2].pos){
				if(bs[i2].type==1) ms.insert(bs[i2].H);
				else ms.erase(ms.find(bs[i2].H));
				i2++;
			}
			if(*ms.begin()!=now){
				now=*ms.begin();
				printf("%d %d ",bs[i].pos,now);
			}
			i=i2;
		}
		printf("\n");
	}
}
