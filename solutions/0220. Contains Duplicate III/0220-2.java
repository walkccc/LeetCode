class Solution {
  public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {
    if (nums.length == 0 || k <= 0 || t < 0)
      return false;

    final long min = Arrays.stream(nums).min().getAsInt();
    final long diff = (long) t + 1; // in case of t = 0
    // use Long because of corner case Integer.MAX_VALUE - (-1) will overflow
    HashMap<Long, Long> bucket = new HashMap<>();

    for (int i = 0; i < nums.length; ++i) {
      final long num = (long) nums[i];
      final long key = getKey(nums[i], min, diff);
      if (bucket.containsKey(key)) // current bucket
        return true;
      if (bucket.containsKey(key - 1) && num - bucket.get(key - 1) < diff) // left adjacent bucket
        return true;
      if (bucket.containsKey(key + 1) && bucket.get(key + 1) - num < diff) // right adjacent bucket
        return true;
      bucket.put(key, num);
      if (i >= k)
        bucket.remove(getKey(nums[i - k], min, diff));
    }

    return false;
  }

  private long getKey(int num, long min, long diff) {
    return ((long) num - min) / diff;
  }
}
