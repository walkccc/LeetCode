class Solution {
  public List<List<Integer>> findMissingRanges(int[] nums, int lower, int upper) {
    if (nums.length == 0)
      return List.of(getRange(lower, upper));

    List<List<Integer>> ans = new ArrayList<>();

    if (nums[0] > lower)
      ans.add(getRange(lower, nums[0] - 1));

    for (int i = 1; i < nums.length; ++i)
      if (nums[i] > nums[i - 1] + 1)
        ans.add(getRange(nums[i - 1] + 1, nums[i] - 1));

    if (nums[nums.length - 1] < upper)
      ans.add(getRange(nums[nums.length - 1] + 1, upper));

    return ans;
  }

  private List<Integer> getRange(int lo, int hi) {
    if (lo == hi)
      return List.of(lo, lo);
    return List.of(lo, hi);
  }
}
