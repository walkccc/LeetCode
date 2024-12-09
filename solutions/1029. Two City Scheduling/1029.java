class Solution {
  public int twoCitySchedCost(int[][] costs) {
    final int n = costs.length / 2;
    int ans = 0;

    // How much money can we save if we fly a person to A instead of B?
    // To save money, we should
    //   1. Fly the person with the maximum saving to A.
    //   2. Fly the person with the minimum saving to B.

    // Sort `costs` in ascending order by the money saved if we fly a person to
    // B instead of A.
    Arrays.sort(costs, (a, b) -> Integer.compare(a[0] - a[1], b[0] - b[1]));

    for (int i = 0; i < n; ++i)
      ans += costs[i][0] + costs[i + n][1];

    return ans;
  }
}
