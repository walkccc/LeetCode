class Solution {
  public long minCuttingCost(long n, long m, int k) {
    return Math.max(0, Math.max(n, m) - k) * k;
  }
}
