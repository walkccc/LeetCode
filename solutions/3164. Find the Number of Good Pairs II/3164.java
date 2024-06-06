class Solution {
  public long numberOfPairs(int[] nums1, int[] nums2, int k) {
    HashMap<Integer, Integer> count = new HashMap<>();
    long ans = 0;

    for (final int num : nums2)
      count.merge(num * k, 1, Integer::sum);

    for (final int num : nums1)
      for (int divisor = 1; divisor <= (int) Math.sqrt(num); ++divisor)
        if (num % divisor == 0) {
          ans += count.getOrDefault(divisor, 0);
          if (num / divisor != divisor)
            ans += count.getOrDefault(num / divisor, 0);
        }

    return ans;
  }
}
