class Solution {
  public int minIncrements(int n, int[] cost) {
    int ans = 0;

    for (int i = n / 2 - 1; i >= 0; --i) {
      final int l = i * 2 + 1;
      final int r = i * 2 + 2;
      ans += Math.abs(cost[l] - cost[r]);
      // Record the information in parent from children. So, no need to actually
      // update the values in children.
      cost[i] += Math.max(cost[l], cost[r]);
    }

    return ans;
  }
}
