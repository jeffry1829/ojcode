#include<bits/stdc++.h>
#define lli long long
using namespace std;
stack<lli> dec1,dec2;
int main(void){
	lli N;
	vector<lli> H;
	scanf("%lld",&N);
	lli ans=2*N-2;
	for(lli i=0;i<N;i++){
		lli tmp;
		scanf("%lld",&tmp);
		H.push_back(tmp);
	}
	for(lli i=0;i<N;i++){
		if(!dec1.empty()&&dec1.top()==H[i]) ans++;
		while(!dec1.empty()&&dec1.top()<H[i]){
			dec1.pop();
			if(dec1.size()==0) ans--;
			ans++;
		}
		dec1.push(H[i]);
	}
	for(lli i=N-1;i>=0;i--){
		//if(!dec2.empty()&&dec2.top()==H[i]) ans++;
		while(!dec2.empty()&&dec2.top()<H[i]){
			dec2.pop();
			if(dec2.size()==0) ans--;
			ans++;
		}
		dec2.push(H[i]);
	}
	printf("%lld",ans);
}
