class Solution {
  public int findLHS(int[] nums) {
    int ans = 0;
    Map<Integer, Integer> count = new HashMap<>();

    for (final int num : nums)
      count.put(num, count.getOrDefault(num, 0) + 1);

    for (final int num : count.keySet())
      if (count.containsKey(num + 1))
        ans = Math.max(ans, count.get(num) + count.get(num + 1));

    return ans;
  }
}
