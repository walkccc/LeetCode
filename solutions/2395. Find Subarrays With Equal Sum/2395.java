class Solution {
  public boolean findSubarrays(int[] nums) {
    Set<Integer> seen = new HashSet<>();

    for (int i = 1; i < nums.length; ++i) {
      final int sum = nums[i - 1] + nums[i];
      if (seen.contains(sum))
        return true;
      seen.add(sum);
    }

    return false;
  }
}
