class Solution {
  public int minimumCost(int[] cost) {
    int ans = 0;

    cost = Arrays.stream(cost)
               .boxed()
               .sorted(Collections.reverseOrder())
               .mapToInt(Integer::intValue)
               .toArray();

    for (int i = 0; i < cost.length; ++i)
      if (i % 3 != 2)
        ans += cost[i];

    return ans;
  }
}
