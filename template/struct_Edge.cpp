struct E {
  int f, t, w;
  bool operator<(const E& rhs) const { return w < rhs.w; }
};