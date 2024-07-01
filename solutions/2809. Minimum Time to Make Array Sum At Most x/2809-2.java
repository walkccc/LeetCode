class Solution {
  public int minimumTime(List<Integer> nums1, List<Integer> nums2, int x) {
    final int n = nums1.size();
    final int sum1 = nums1.stream().mapToInt(Integer::intValue).sum();
    final int sum2 = nums2.stream().mapToInt(Integer::intValue).sum();
    // dp[j] := the maximum reduced value if we do j operations on the numbers
    // so far
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
            // the maximum reduced value if we do j operations on the first
            // i - 1 numbers
            dp[j],
            // the maximum reduced value if we do j - 1 operations on the first
            // i - 1 numbers + making the i-th number of `nums1` to 0 at the
            // j-th operation
            dp[j - 1] + num2 * j + num1);
    }

    for (int op = 0; op <= n; ++op)
      if (sum1 + sum2 * op - dp[op] <= x)
        return op;

    return -1;
  }
}
