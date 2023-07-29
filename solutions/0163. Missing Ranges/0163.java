class Solution {
  public List<String> findMissingRanges(int[] nums, int lower, int upper) {
    if (nums.length == 0)
      return new ArrayList<>(Arrays.asList(getRange(lower, upper)));

    List<String> ans = new ArrayList<>();

    if (nums[0] > lower)
      ans.add(getRange(lower, nums[0] - 1));

    for (int i = 1; i < nums.length; ++i)
      if (nums[i] > nums[i - 1] + 1)
        ans.add(getRange(nums[i - 1] + 1, nums[i] - 1));

    if (nums[nums.length - 1] < upper)
      ans.add(getRange(nums[nums.length - 1] + 1, upper));

    return ans;
  }

  private String getRange(int lo, int hi) {
    if (lo == hi)
      return String.valueOf(lo);
    return lo + "->" + hi;
  }
}
