class Solution {
  public List<Integer> findDisappearedNumbers(int[] nums) {
    List<Integer> ans = new ArrayList<>();

    for (final int num : nums) {
      final int index = Math.abs(num) - 1;
      nums[index] = -Math.abs(nums[index]);
    }

    for (int i = 0; i < nums.length; ++i)
      if (nums[i] > 0)
        ans.add(i + 1);

    return ans;
  }
}