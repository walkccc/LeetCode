class Solution {
  public int findNumberOfLIS(int[] nums) {
    final int n = nums.length;
    int ans = 0;
    int maxLength = 0;
    // length[i] := the length of the LIS ending in nums[i]
    int[] length = new int[n];
    // count[i] := the number of LIS's ending in nums[i]
    int[] count = new int[n];

    Arrays.fill(length, 1);
    Arrays.fill(count, 1);

    // Calculate the `length` and `count` arrays.
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < i; ++j)
        if (nums[j] < nums[i])
          if (length[i] < length[j] + 1) {
            length[i] = length[j] + 1;
            count[i] = count[j];
          } else if (length[i] == length[j] + 1) {
            count[i] += count[j];
          }

    // Get the number of LIS.
    for (int i = 0; i < n; ++i)
      if (length[i] > maxLength) {
        maxLength = length[i];
        ans = count[i];
      } else if (length[i] == maxLength) {
        ans += count[i];
      }

    return ans;
  }
}
