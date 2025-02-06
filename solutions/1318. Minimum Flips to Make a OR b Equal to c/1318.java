class Solution {
  public int minFlips(int a, int b, int c) {
    final int kMaxBit = 30;
    int ans = 0;

    for (int i = 0; i < kMaxBit; ++i)
      if ((c >> i & 1) == 1)
        ans += ((a >> i & 1) == 0 && (b >> i & 1) == 0) ? 1 : 0;
      else // (c >> i & 1) == 0
        ans += ((a >> i & 1) == 1 ? 1 : 0) + ((b >> i & 1) == 1 ? 1 : 0);

    return ans;
  }
}
