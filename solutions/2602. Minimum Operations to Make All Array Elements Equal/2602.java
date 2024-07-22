class Solution {
  public List<Long> minOperations(int[] nums, int[] queries) {
    final int n = nums.length;
    List<Long> ans = new ArrayList<>();
    long[] prefix = new long[n + 1];

    Arrays.sort(nums);

    for (int i = 0; i < n; ++i)
      prefix[i + 1] = prefix[i] + nums[i];

    for (final int query : queries) {
      int i = Arrays.binarySearch(nums, query);
      if (i < 0)
        i = -i - 1;

      // Since nums[0..i) <= query, nums[i..n) > `query`, we should
      // - increase each num in nums[0..i) to `query` and
      // - decrease each num in nums[i..n) to `query`.
      final long inc = (long) query * i - prefix[i];
      final long dec = prefix[n] - prefix[i] - (long) query * (n - i);
      ans.add(inc + dec);
    }

    return ans;
  }
}
