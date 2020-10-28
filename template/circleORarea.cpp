vector<pair<db,db>> CoverSegment(C &a,C &b){
  db d=(a.c-b.c).abs();
  vector<pair<db,db>> res;
  if(same(a.r+b.r,d));
  else if(d<=abs(a.r-b.r)+eps){
    if(a.r<b.r)res.pb({0,2*pi});
  }else if(d<abs(a.r+b.r)-eps){
    db o=acos((sq(a.r)+sq(d)-sq(b.r))/(2*a.r*d)),z=(b.c-a.c).angle();
    if(z<0)z+=2*pi;
    db l=z-o,r=z+o;
    if(l<0)l+=2*pi;if(r>2*pi)r-=2*pi;
    if(l>r)res.pb({l,2*pi}),res.pb({0,r});
    else res.pb({l,r});
  }return res;
}
db CircleUnionArea(vector<C> &c){//circles should be unique
  db res=0;
  rep(i,0,SZ(c)){
    db w=0;vector<pair<db,db>> s={{2*pi,9}},z;
    rep(j,0,SZ(c))if(i!=j){
      z=CoverSegment(c[i],c[j]);
      for(auto &e:z)s.pb(e);
    }sort(all(s));
    auto f=[&](db t){return c[i].r*(c[i].c.x*sin(t)-c[i].c.y*cos(t)+c[i].c.y+c[i].r*t);};
    for(auto &e:s){
      if(e.fi>w)res+=f(e.fi)-f(w);
      w=max(w,e.se);
    }
  }return res/2;
}