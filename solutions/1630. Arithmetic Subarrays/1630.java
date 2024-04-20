class Solution {
  public List<Boolean> checkArithmeticSubarrays(int[] nums, int[] l, int[] r) {
    List<Boolean> ans = new ArrayList<>();

    for (int i = 0; i < l.length; ++i)
      ans.add(isArithmetic(nums, l[i], r[i]));

    return ans;
  }

  private boolean isArithmetic(int[] nums, int l, int r) {
    if (r - l < 2)
      return true;

    int min = Integer.MAX_VALUE;
    int max = Integer.MIN_VALUE;
    Set<Integer> numsSet = new HashSet<>();

    for (int i = l; i <= r; ++i) {
      min = Math.min(min, nums[i]);
      max = Math.max(max, nums[i]);
      numsSet.add(nums[i]);
    }

    if ((max - min) % (r - l) != 0)
      return false;

    final int interval = (max - min) / (r - l);

    for (int k = 1; k <= r - l; ++k)
      if (!numsSet.contains(min + k * interval))
        return false;

    return true;
  }
}
