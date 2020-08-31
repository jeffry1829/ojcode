//注意:Z-algo的Z[i]代表從i開始的(0-base)
int L = 0, R = 0;
for (int i = 1; i < LEN; i++) {
  if (i > R) {
    L = R = i;
    while (R < n && s[R-L] == s[R]) R++;
    Z[i] = R-L; R--;
  } else {
    int k = i-L;
    if (Z[k] < R-i+1) Z[i] = Z[k];
    else {
      L = i;
      while (R < n && s[R-L] == s[R]) R++;
      Z[i] = R-L; R--;
    }
  }
}