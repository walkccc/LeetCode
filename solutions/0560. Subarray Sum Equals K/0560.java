class Solution {
  public int subarraySum(int[] nums, int k) {
    int ans = 0;
    int prefixSum = 0;
    Map<Integer, Integer> count = new HashMap<>();
    count.put(0, 1);

    for (int num : nums) {
      prefixSum += num;
      ans += count.getOrDefault(prefixSum - k, 0);
      count.put(prefixSum, count.getOrDefault(prefixSum, 0) + 1);
    }

    return ans;
  }
}