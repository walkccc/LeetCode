class Solution {
  public int getLargestOutlier(int[] nums) {
    final int sum = Arrays.stream(nums).sum();
    int ans = Integer.MIN_VALUE;
    Map<Integer, Integer> count = new HashMap<>();

    for (final int num : nums)
      count.merge(num, 1, Integer::sum);

    for (final int num : nums) {
      final int withoutNum = sum - num;
      if (withoutNum % 2 == 0) {
        final int specialSum = withoutNum / 2; // the sum of special numbers
        if (count.getOrDefault(specialSum, 0) > (num == specialSum ? 1 : 0))
          ans = Math.max(ans, num);
      }
    }

    return ans;
  }
}
