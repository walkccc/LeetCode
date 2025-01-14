class Solution {
  public int minLengthAfterRemovals(List<Integer> nums) {
    final int n = nums.size();
    Map<Integer, Integer> count = new HashMap<>();
    int maxFreq = 0;

    for (final int num : nums)
      count.merge(num, 1, Integer::sum);

    for (final int freq : count.values())
      maxFreq = Math.max(maxFreq, freq);

    // The number with the maximum frequency cancel all the other numbers.
    if (maxFreq <= n / 2)
      return n % 2;
    // The number with the maximum frequency cancel all the remaining numbers.
    return maxFreq - (n - maxFreq);
  }
}
