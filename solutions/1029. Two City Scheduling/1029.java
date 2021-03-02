class Solution {
  public int twoCitySchedCost(int[][] costs) {
    final int n = costs.length / 2;

    int ans = 0;

    // assume send 2n people to city b at first, but actually we have to send n
    // people to city a as well, so we sort by "how much will be refunded" if we
    // send a person to city a instead of city b, i.e., -(costs[1] - costs[0])
    Arrays.sort(costs, (a, b) -> (a[0] - a[1]) - (b[0] - b[1]));

    for (int i = 0; i < n; ++i)
      ans += costs[i][0] + costs[i + n][1];

    return ans;
  }
}
