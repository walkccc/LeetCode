class Solution {
  public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {
    TreeSet<Long> set = new TreeSet<>();

    for (int i = 0; i < nums.length; ++i) {
      final long num = (long) nums[i];
      final Long ceiling = set.ceiling(num); // the smallest num >= nums[i]
      if (ceiling != null && ceiling - num <= t)
        return true;
      final Long floor = set.floor(num); // the largest num <= nums[i]
      if (floor != null && num - floor <= t)
        return true;
      set.add(num);
      if (i >= k)
        set.remove((long) nums[i - k]);
    }

    return false;
  }
}
