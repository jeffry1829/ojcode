#include<bits/stdc++.h>
#define int long long
using namespace std;
main(void){
  vector<int> v;
  v.reserve(1000000);
  int n;
  scanf("%lld",&n);
  while(n--){
    int a;
    scanf("%lld",&a);
    v.push_back(a);
  }
  sort(v.begin(),v.end());
  for(int i=0;i<v.size();i++){
    printf("%lld ",v[i]);
  }
  printf("\n");
  return 0;
}
