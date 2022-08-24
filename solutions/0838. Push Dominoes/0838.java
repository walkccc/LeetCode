class Solution {
  public String pushDominoes(String dominoes) {
    char[] s = dominoes.toCharArray();
    int L = -1;
    int R = -1;

    for (int i = 0; i <= dominoes.length(); ++i)
      if (i == dominoes.length() || s[i] == 'R') {
        if (L < R)
          while (R < i)
            s[R++] = 'R';
        R = i;
      } else if (s[i] == 'L') {
        if (R < L || L == -1 && R == -1) {
          if (L == -1 && R == -1)
            ++L;
          while (L < i)
            s[L++] = 'L';
        } else {
          int l = R + 1;
          int r = i - 1;
          while (l < r) {
            s[l++] = 'R';
            s[r--] = 'L';
          }
        }
        L = i;
      }

    return new String(s);
  }
}
