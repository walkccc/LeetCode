class Solution {
  public int smallestDistancePair(int[] nums, int k) {
    Arrays.sort(nums);

    int l = 0;
    int r = nums[nums.length - 1] - nums[0];

    while (l < r) {
      int m = l + (r - l) / 2;
      int count = 0;

      for (int i = 0, j = 0; i < nums.length; ++i) {
        while (j < nums.length && nums[j] <= nums[i] + m)
          ++j;
        count += j - i - 1;
      }

      if (count < k)
        l = m + 1;
      else
        r = m;
    }

    return l;
  }
}