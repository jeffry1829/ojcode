stack<int> s;rep(i,0,n){
  while(!s.empty() and m[s.top()]>m[i])s.pop();
  l[i]=s.empty()?-1:s.top();
  s.push(i);
}