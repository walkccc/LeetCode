class Solution {
  public int[] minCosts(int[] cost) {
    int[] ans = new int[cost.length];
    int minCost = Integer.MAX_VALUE;
    for (int i = 0; i < cost.length; ++i) {
      minCost = Math.min(minCost, cost[i]);
      ans[i] = minCost;
    }
    return ans;
  }
}
