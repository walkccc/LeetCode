class Solution {
  public int maxSubArray(int[] nums) {
    return divideAndConquer(nums, 0, nums.length - 1).maxSubarraySum;
  }

  private T divideAndConquer(int[] nums, int l, int r) {
    if (l == r)
      return new T(nums[l], nums[l], nums[l], nums[l]);

    final int m = (l + r) / 2;
    final T t1 = divideAndConquer(nums, l, m);
    final T t2 = divideAndConquer(nums, m + 1, r);

    final int maxSubarraySumLeft = Math.max(t1.maxSubarraySumLeft, t1.sum + t2.maxSubarraySumLeft);
    final int maxSubarraySumRight =
        Math.max(t1.maxSubarraySumRight + t2.sum, t2.maxSubarraySumRight);
    final int maxSubarraySum = Math.max(t1.maxSubarraySumRight + t2.maxSubarraySumLeft,
                                        Math.max(t1.maxSubarraySum, t2.maxSubarraySum));
    final int sum = t1.sum + t2.sum;
    return new T(maxSubarraySumLeft, maxSubarraySumRight, maxSubarraySum, sum);
  }

  private record T(
      // the sum of the subarray starting from the first number
      int maxSubarraySumLeft,
      // the sum of the subarray ending in the last number
      int maxSubarraySumRight, //
      int maxSubarraySum, int sum) {}
}
