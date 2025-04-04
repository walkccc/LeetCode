class Solution {
  public List<Integer> findDuplicates(int[] nums) {
    List<Integer> ans = new ArrayList<>();

    for (final int num : nums) {
      nums[Math.abs(num) - 1] *= -1;
      if (nums[Math.abs(num) - 1] > 0)
        ans.add(Math.abs(num));
    }

    return ans;
  }
}
