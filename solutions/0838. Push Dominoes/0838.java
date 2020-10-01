class Solution {
  public String pushDominoes(String dominoes) {
    char[] ans = dominoes.toCharArray();
    int L = -1;
    int R = -1;

    for (int i = 0; i <= dominoes.length(); ++i)
      if (i == dominoes.length() || ans[i] == 'R') {
        if (L < R)
          while (R < i)
            ans[R++] = 'R';
        R = i;
      } else if (ans[i] == 'L') {
        if (R < L || L == -1 && R == -1) {
          if (L == -1 && R == -1)
            ++L;
          while (L < i)
            ans[L++] = 'L';
        } else {
          int l = R + 1;
          int r = i - 1;
          while (l < r) {
            ans[l++] = 'R';
            ans[r--] = 'L';
          }
        }
        L = i;
      }

    return new String(ans);
  }
}