struct mat{
  int a[_n][_n];
  mat(){memset(a,0,sizeof a);}
  mat operator*(const mat& rhs)const{
    mat res;
    rep(i,0,n)rep(j,0,n){
      res.a[i][j]=-1e5;
      rep(k,0,n)res.a[i][j]=max(res.a[i][j],a[i][k]+rhs.a[k][j]);
    }
    return res;
  }
  mat operator^(int b){
    mat res,tmp=*this;
    while(b){
      if(b&1)res=res*tmp;
      b>>=1;tmp=tmp*tmp;
    }
    return res;
  }
};