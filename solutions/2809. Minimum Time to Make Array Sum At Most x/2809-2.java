class Solution {
  public int minimumTime(List<Integer> nums1, List<Integer> nums2, int x) {
    final int n = nums1.size();
    final int sum1 = nums1.stream().mapToInt(Integer::intValue).sum();
    final int sum2 = nums2.stream().mapToInt(Integer::intValue).sum();
    // dp[j] := max reduced value if we do j ops on the nums so far
    int[] dp = new int[n + 1];
    List<Pair<Integer, Integer>> sortedNums = new ArrayList<>();

    for (int i = 0; i < n; ++i)
      sortedNums.add(new Pair<>(nums2.get(i), nums1.get(i)));

    sortedNums.sort(Comparator.comparingInt(a -> a.getKey()));

    for (int i = 1; i <= n; ++i) {
      final int num2 = sortedNums.get(i - 1).getKey();
      final int num1 = sortedNums.get(i - 1).getValue();
      for (int j = i; j > 0; --j)
        dp[j] = Math.max(
            // max reduced value if we do j ops on the first i - 1 nums
            dp[j],
            // max reduced value if we do j - 1 ops on the first i - 1 nums +
            // making i-th num of nums1 to 0 at j-th operation
            dp[j - 1] + num2 * j + num1);
    }

    for (int op = 0; op <= n; ++op)
      if (sum1 + sum2 * op - dp[op] <= x)
        return op;

    return -1;
  }
}
