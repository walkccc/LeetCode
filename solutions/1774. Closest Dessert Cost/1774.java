class Solution {
  public int closestCost(int[] baseCosts, int[] toppingCosts, int target) {
    for (final int baseCost : baseCosts)
      dfs(toppingCosts, 0, target, baseCost);
    return ans;
  }

  private int ans = Integer.MAX_VALUE;

  private void dfs(int[] toppingCosts, int i, int target, int currCost) {
    if (Math.abs(currCost - target) < Math.abs(ans - target))
      ans = currCost;
    if (i == toppingCosts.length || currCost >= target)
      return;

    for (int k = 0; k < 3; ++k)
      dfs(toppingCosts, i + 1, target, currCost + k * toppingCosts[i]);
  }
}
