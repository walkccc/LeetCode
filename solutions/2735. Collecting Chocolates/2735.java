public class Solution {
  public long minCost(int[] nums, long x) {
    int n = nums.length;
    long ans = Long.MAX_VALUE;
    // minCost[i] := the minimum cost to collect the i-th type
    int[] minCost = new int[n];
    Arrays.fill(minCost, Integer.MAX_VALUE);

    for (int rotate = 0; rotate < n; ++rotate) {
      for (int i = 0; i < n; ++i)
        minCost[i] = Math.min(minCost[i], nums[(i - rotate + n) % n]);
      ans = Math.min(ans, Arrays.stream(minCost).asLongStream().sum() + rotate * x);
    }

    return ans;
  }
}
