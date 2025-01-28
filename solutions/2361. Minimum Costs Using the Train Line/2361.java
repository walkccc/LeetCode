class Solution {
  public long[] minimumCosts(int[] regular, int[] express, int expressCost) {
    final int n = regular.length;
    long[] ans = new long[n];
    // the minimum cost to reach the current stop in a regular route
    long dpReg = 0;
    // the minimum cost to reach the current stop in an express route
    long dpExp = expressCost;

    for (int i = 0; i < n; ++i) {
      final long prevReg = dpReg;
      final long prevExp = dpExp;
      dpReg = Math.min(prevReg + regular[i], prevExp + 0 + regular[i]);
      dpExp = Math.min(prevReg + expressCost + express[i], prevExp + express[i]);
      ans[i] = Math.min(dpReg, dpExp);
    }

    return ans;
  }
}
