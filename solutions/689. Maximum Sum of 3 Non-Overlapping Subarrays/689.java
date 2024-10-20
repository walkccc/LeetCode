class Solution {
  public int[] maxSumOfThreeSubarrays(int[] nums, int k) {
    final int n = nums.length - k + 1;
    // sums[i] := sum(nums[i..i + k))
    int[] sums = new int[n];
    // l[i] := the index in [0..i] that has the maximum sums[i]
    int[] l = new int[n];
    // r[i] := the index in [i..n) that has the maximum sums[i]
    int[] r = new int[n];

    int sum = 0;
    for (int i = 0; i < nums.length; ++i) {
      sum += nums[i];
      if (i >= k)
        sum -= nums[i - k];
      if (i >= k - 1)
        sums[i - k + 1] = sum;
    }

    int maxIndex = 0;
    for (int i = 0; i < n; ++i) {
      if (sums[i] > sums[maxIndex])
        maxIndex = i;
      l[i] = maxIndex;
    }

    maxIndex = n - 1;
    for (int i = n - 1; i >= 0; --i) {
      if (sums[i] >= sums[maxIndex])
        maxIndex = i;
      r[i] = maxIndex;
    }

    int[] ans = {-1, -1, -1};

    for (int i = k; i + k < n; ++i)
      if (ans[0] == -1 ||
          sums[ans[0]] + sums[ans[1]] + sums[ans[2]] < sums[l[i - k]] + sums[i] + sums[r[i + k]]) {
        ans[0] = l[i - k];
        ans[1] = i;
        ans[2] = r[i + k];
      }

    return ans;
  }
}
