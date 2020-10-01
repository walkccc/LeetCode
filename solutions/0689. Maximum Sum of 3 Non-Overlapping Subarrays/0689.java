class Solution {
  public int[] maxSumOfThreeSubarrays(int[] nums, int k) {
    int[] ans = new int[] { -1, -1, -1 };
    int subarrayCount = nums.length - k + 1;
    int[] dp = new int[subarrayCount];
    int sum = 0;

    for (int i = 0; i < nums.length; ++i) {
      sum += nums[i];
      if (i >= k)
        sum -= nums[i - k];
      if (i >= k - 1)
        dp[i - k + 1] = sum;
    }

    int[] left = new int[subarrayCount];
    int maxIndex = 0;

    for (int i = 0; i < subarrayCount; ++i) {
      if (dp[i] > dp[maxIndex])
        maxIndex = i;
      left[i] = maxIndex;
    }

    int[] right = new int[subarrayCount];
    maxIndex = subarrayCount - 1;

    for (int i = subarrayCount - 1; i >= 0; --i) {
      if (dp[i] >= dp[maxIndex])
        maxIndex = i;
      right[i] = maxIndex;
    }

    for (int i = k; i < subarrayCount - k; ++i)
      if (ans[0] == -1 || dp[left[i - k]] + dp[i] + dp[right[i + k]] > dp[ans[0]] + dp[ans[1]] + dp[ans[2]]) {
        ans[0] = left[i - k];
        ans[1] = i;
        ans[2] = right[i + k];
      }

    return ans;
  }
}