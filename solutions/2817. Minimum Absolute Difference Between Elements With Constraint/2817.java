class Solution {
  public int minAbsoluteDifference(List<Integer> nums, int x) {
    int ans = Integer.MAX_VALUE;
    TreeSet<Integer> seen = new TreeSet<>();

    for (int i = x; i < nums.size(); ++i) {
      seen.add(nums.get(i - x));
      Integer hi = seen.ceiling(nums.get(i));
      if (hi != null)
        ans = Math.min(ans, hi - nums.get(i));
      Integer lo = seen.floor(nums.get(i));
      if (lo != null)
        ans = Math.min(ans, nums.get(i) - lo);
    }

    return ans;
  }
}
