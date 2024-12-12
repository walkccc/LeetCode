class Solution {
  public int maxA(int n) {
    int ans = n;

    for (int i = 1; i <= n - 3; ++i)
      ans = Math.max(ans, maxA(i) * (n - 1 - i));

    return ans;
  }
}
