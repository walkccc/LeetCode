class Solution {
  public int subarraySum(int[] nums, int k) {
    int ans = 0;
    int prefix = 0;
    Map<Integer, Integer> count = new HashMap<>();
    count.put(0, 1);

    for (final int num : nums) {
      prefix += num;
      ans += count.getOrDefault(prefix - k, 0);
      count.merge(prefix, 1, Integer::sum);
    }

    return ans;
  }
}
