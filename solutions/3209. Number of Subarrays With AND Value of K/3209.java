class Solution {
  // Similar to 1521. Find a Value of a Mysterious Function Closest to Target
  public long countSubarrays(int[] nums, int k) {
    long ans = 0;
    // the counter of all the values of subarrays that end in the previous
    // number
    Map<Integer, Integer> prev = new HashMap<>();

    for (final int num : nums) {
      Map<Integer, Integer> curr = new HashMap<>() {
        { put(num, 1); }
      };
      // Extend each subarray that ends in the previous number. Due to
      // monotonicity of the AND operation, the size of `curr` will be at most
      // Integer.bitCount(num) + 1.
      for (Map.Entry<Integer, Integer> entry : prev.entrySet()) {
        final int val = entry.getKey();
        final int freq = entry.getValue();
        curr.merge(val & num, freq, Integer::sum);
      }
      ans += curr.getOrDefault(k, 0);
      prev = curr;
    }

    return ans;
  }
}
