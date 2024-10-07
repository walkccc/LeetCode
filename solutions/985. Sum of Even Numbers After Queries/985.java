class Solution {
  public int[] sumEvenAfterQueries(int[] nums, int[][] queries) {
    int[] ans = new int[queries.length];
    int sum = 0;

    for (final int num : nums)
      sum += num % 2 == 0 ? num : 0;

    for (int i = 0; i < queries.length; ++i) {
      final int val = queries[i][0];
      final int index = queries[i][1];
      if (nums[index] % 2 == 0)
        sum -= nums[index];
      nums[index] += val;
      if (nums[index] % 2 == 0)
        sum += nums[index];
      ans[i] = sum;
    }

    return ans;
  }
}
