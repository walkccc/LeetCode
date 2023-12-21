class Solution {
  public boolean containsNearbyAlmostDuplicate(int[] nums, int indexDiff, int valueDiff) {
    if (nums.length == 0 || indexDiff <= 0 || valueDiff < 0)
      return false;

    final long min = Arrays.stream(nums).min().getAsInt();
    final long diff = (long) valueDiff + 1; // In case that `valueDiff` equals 0.
    // Use Long because of corner case Integer.MAX_VALUE - (-1) will overflow
    HashMap<Long, Long> bucket = new HashMap<>();

    for (int i = 0; i < nums.length; ++i) {
      final long num = (long) nums[i];
      final long key = getKey(nums[i], min, diff);
      if (bucket.containsKey(key)) // the current bucket
        return true;
      if (bucket.containsKey(key - 1) &&
          num - bucket.get(key - 1) < diff) // the left adjacent bucket
        return true;
      if (bucket.containsKey(key + 1) &&
          bucket.get(key + 1) - num < diff) // the right adjacent bucket
        return true;
      bucket.put(key, num);
      if (i >= indexDiff)
        bucket.remove(getKey(nums[i - indexDiff], min, diff));
    }

    return false;
  }

  private long getKey(int num, long min, long diff) {
    return ((long) num - min) / diff;
  }
}
