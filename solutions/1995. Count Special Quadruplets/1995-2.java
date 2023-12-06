class Solution {
  public int countQuadruplets(int[] nums) {
    final int n = nums.length;
    int ans = 0;
    Map<Integer, Integer> count = new HashMap<>();

    for (int c = n - 1; c > 1; --c) { // Also represents `d`.
      for (int b = c - 1; b > 0; --b)
        for (int a = b - 1; a >= 0; --a)
          ans += count.getOrDefault(nums[a] + nums[b] + nums[c], 0);
      count.merge(nums[c], 1, Integer::sum); // c := d
    }

    return ans;
  }
}
