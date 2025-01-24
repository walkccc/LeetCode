class Solution {
  public long[] maximumSegmentSum(int[] nums, int[] removeQueries) {
    final int n = nums.length;
    long maxSum = 0;
    long[] ans = new long[n];
    // For the segment [l, r], record its sum in sum[l] and sum[r]
    long[] sum = new long[n];
    // For the segment [l, r], record its count in count[l] and count[r]
    int[] count = new int[n];

    for (int i = n - 1; i >= 0; --i) {
      ans[i] = maxSum;
      final int j = removeQueries[i];

      // Calculate `segmentSum`.
      final long leftSum = j > 0 ? sum[j - 1] : 0;
      final long rightSum = j + 1 < n ? sum[j + 1] : 0;
      final long segmentSum = nums[j] + leftSum + rightSum;

      // Calculate `segmentCount`.
      final int leftCount = j > 0 ? count[j - 1] : 0;
      final int rightCount = j + 1 < n ? count[j + 1] : 0;
      final int segmentCount = 1 + leftCount + rightCount;

      // Update the sum and count of the segment [l, r].
      final int l = j - leftCount;
      final int r = j + rightCount;
      sum[l] = segmentSum;
      sum[r] = segmentSum;
      count[l] = segmentCount;
      count[r] = segmentCount;
      maxSum = Math.max(maxSum, segmentSum);
    }

    return ans;
  }
}
