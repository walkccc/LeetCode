class Solution {
  public int findNumberOfLIS(int[] nums) {
    final int n = nums.length;
    int ans = 0;
    int maxLength = 0;
    int[] length = new int[n]; // length[i] := LIS's length ending w/ nums[i]
    int[] count = new int[n];  // count[i] := # of the LIS ending w/ nums[i]

    Arrays.fill(length, 1);
    Arrays.fill(count, 1);

    // calculate length and count arrays
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < i; ++j)
        if (nums[j] < nums[i])
          if (length[i] < length[j] + 1) {
            length[i] = length[j] + 1;
            count[i] = count[j];
          } else if (length[i] == length[j] + 1) {
            count[i] += count[j];
          }

    // get # of LIS
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
