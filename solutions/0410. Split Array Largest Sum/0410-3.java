class Solution {
  public int splitArray(int[] nums, int m) {
    int l = Arrays.stream(nums).max().getAsInt();
    int r = Arrays.stream(nums).sum() + 1;

    while (l < r) {
      final int mid = (l + r) / 2;
      if (numGroups(nums, mid) > m)
        l = mid + 1;
      else
        r = mid;
    }

    return l;
  }

  private int numGroups(int[] nums, int maxSumInGroup) {
    int groupCount = 1;
    int sumInGroup = 0;

    for (final int num : nums)
      if (sumInGroup + num <= maxSumInGroup) {
        sumInGroup += num;
      } else {
        ++groupCount;
        sumInGroup = num;
      }

    return groupCount;
  }
}
