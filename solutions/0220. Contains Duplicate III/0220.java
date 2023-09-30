class Solution {
  public boolean containsNearbyAlmostDuplicate(int[] nums, int indexDiff, int valueDiff) {
    TreeSet<Long> set = new TreeSet<>();

    for (int i = 0; i < nums.length; ++i) {
      final long num = (long) nums[i];
      final Long ceiling = set.ceiling(num); // The smallest num >= nums[i]
      if (ceiling != null && ceiling - num <= valueDiff)
        return true;
      final Long floor = set.floor(num); // The largest num <= nums[i]
      if (floor != null && num - floor <= valueDiff)
        return true;
      set.add(num);
      if (i >= indexDiff)
        set.remove((long) nums[i - indexDiff]);
    }

    return false;
  }
}
