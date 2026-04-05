class Solution {
  public int countQuadruplets(int[] nums) {
    final int n = nums.length;
    int ans = 0;
    Map<Integer, Integer> count = new HashMap<>();

    //    nums[a] + nums[b] + nums[c] == nums[d]
    // => nums[a] + nums[b] == nums[d] - nums[c]
    for (int b = n - 1; b > 0; --b) { // `b` also represents `c`.
      for (int a = b - 1; a >= 0; --a)
        ans += count.getOrDefault(nums[a] + nums[b], 0);
      for (int d = n - 1; d > b; --d)
        count.merge(nums[d] - nums[b], 1, Integer::sum); // b := c
    }

    return ans;
  }
}
