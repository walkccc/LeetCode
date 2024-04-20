class Solution {
  public int[] countBits(int n) {
    // f(i) := i's number of 1s in bitmask
    // f(i) = f(i / 2) + i % 2
    int[] ans = new int[n + 1];

    for (int i = 1; i <= n; ++i)
      ans[i] = ans[i / 2] + (i % 2);

    return ans;
  }
}
