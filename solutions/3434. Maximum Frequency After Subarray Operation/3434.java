class Solution {
  public int maxFrequency(int[] nums, int k) {
    final int MAX = 50;
    int maxFreq = 0;
    for (int target = 1; target <= MAX; ++target)
      if (target != k)
        maxFreq = Math.max(maxFreq, kadane(nums, target, k));
    return (int) Arrays.stream(nums).filter(num -> num == k).count() + maxFreq;
  }

  // Returns the maximum achievable frequency of `k` using Kakane's algorithm,
  // where each `target` in subarrays is transformed to `k`.
  private int kadane(int[] nums, int target, int k) {
    int maxSum = 0;
    int sum = 0;
    for (final int num : nums) {
      if (num == target)
        ++sum;
      else if (num == k)
        --sum;
      if (sum < 0) // Reset if sum becomes negative (Kadane's spirit).
        sum = 0;
      maxSum = Math.max(maxSum, sum);
    }

    return maxSum;
  }
}
