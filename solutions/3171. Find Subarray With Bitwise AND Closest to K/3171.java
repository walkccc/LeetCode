class Solution {
  // Similar to 1521. Find a Value of a Mysterious Function Closest to Target
  public int minimumDifference(int[] nums, int k) {
    int ans = Integer.MAX_VALUE;
    // all the values of subarrays that end in the previous number
    Set<Integer> prev = new HashSet<>();

    for (final int num : nums) {
      HashSet<Integer> next = new HashSet<>(Arrays.asList(num));
      // Extend each subarray that ends in the previous number. Due to
      // monotonicity of the OR operation, the size of `next` will be at most
      // Integer.bitCount(num) + 1.
      for (final int val : prev)
        next.add(val | num);
      for (final int val : next)
        ans = Math.min(ans, Math.abs(k - val));
      prev = next;
    }

    return ans;
  }
}
