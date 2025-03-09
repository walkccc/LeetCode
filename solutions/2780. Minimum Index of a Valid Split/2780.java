class Solution {
  public int minimumIndex(List<Integer> nums) {
    final int n = nums.size();
    Map<Integer, Integer> count1 = new HashMap<>();
    Map<Integer, Integer> count2 = new HashMap<>();

    for (final int num : nums)
      count2.merge(num, 1, Integer::sum);

    for (int i = 0; i < n; ++i) {
      final int freq1 = count1.merge(nums.get(i), 1, Integer::sum);
      final int freq2 = count2.merge(nums.get(i), -1, Integer::sum);
      if (freq1 * 2 > i + 1 && freq2 * 2 > n - 1 - i)
        return i;
    }

    return -1;
  }
}
