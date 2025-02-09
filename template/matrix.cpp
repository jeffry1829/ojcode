// template with fastpow and mod
struct Mat {
 public:
  int rlen, clen;
  vector<vector<int>> _a;
  Mat(int rlen, int clen) : rlen(rlen), clen(clen) {
    _a = vector<vector<int>>(rlen, vector<int>(clen, 0));
  }
  Mat operator*(const Mat& rhs) const {
    Mat res(this->rlen, rhs.clen);
    rep(i, 0, res.rlen) rep(j, 0, res.clen) {
      res._a[i][j] = 0;
      rep(k, 0, this->clen) res._a[i][j] = (1ll * res._a[i][j] + 1ll * (_a[i][k] % mod) * (rhs._a[k][j] % mod)) % mod;
    }
    return res;
  }
  Mat operator^(ll b) {
    Mat res(rlen, clen), tmp = *this;
    assert(rlen == clen);
    rep(i, 0, rlen) {
      res._a[i][i] = 1;
    }
    while (b) {
      if (b & 1ll) res = res * tmp;
      b >>= 1ll;
      tmp = tmp * tmp;
    }
    return res;
  }
};