class Solution {
  public int maxSubArray(int[] nums) {
    return divideAndConquer(nums, 0, nums.length - 1).maxSubarraySum;
  }

  private T divideAndConquer(int[] nums, int l, int r) {
    if (l == r)
      return new T(nums[l], nums[l], nums[l], nums[l]);
    final int m = (l + r) / 2;
    final T left = divideAndConquer(nums, l, m);
    final T right = divideAndConquer(nums, m + 1, r);
    final int maxSubarraySumPrefix =
        Math.max(left.maxSubarraySumPrefix, left.sum + right.maxSubarraySumPrefix);
    final int maxSubarraySumSuffix =
        Math.max(left.maxSubarraySumSuffix + right.sum, right.maxSubarraySumSuffix);
    final int maxSubarraySum = Math.max(left.maxSubarraySumSuffix + right.maxSubarraySumPrefix,
                                        Math.max(left.maxSubarraySum, right.maxSubarraySum));
    final int sum = left.sum + right.sum;
    return new T(sum, maxSubarraySumPrefix, maxSubarraySumSuffix, maxSubarraySum);
  }

  private record T(int sum,
                   // the sum of the subarray starting from the first number
                   int maxSubarraySumPrefix,
                   // the sum of the subarray ending in the last number
                   int maxSubarraySumSuffix, //
                   int maxSubarraySum) {}
}
