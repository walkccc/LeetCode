class Solution {
  public int waysToPartition(int[] nums, int k) {
    final int n = nums.length;
    final long sum = Arrays.stream(nums).asLongStream().sum();
    long prefix = 0;
    // count of sum(A[0..k)) - sum(A[k..n)) for k in [0..i)
    Map<Long, Integer> l = new HashMap<>();
    // count of sum(A[0..k)) - sum(A[k..n)) for k in [i..n)
    Map<Long, Integer> r = new HashMap<>();

    for (int pivot = 1; pivot < n; ++pivot) {
      prefix += nums[pivot - 1];
      final long suffix = sum - prefix;
      r.merge(prefix - suffix, 1, Integer::sum);
    }

    int ans = r.getOrDefault(0L, 0);
    prefix = 0;

    for (final int num : nums) {
      final long change = (long) k - num;
      ans = Math.max(ans, l.getOrDefault(change, 0) + r.getOrDefault(-change, 0));
      prefix += num;
      final long suffix = sum - prefix;
      final long diff = prefix - suffix;
      r.merge(diff, -1, Integer::sum);
      l.merge(diff, 1, Integer::sum);
    }

    return ans;
  }
}
