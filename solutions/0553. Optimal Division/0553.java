class Solution {
  public String optimalDivision(int[] nums) {
    String ans = String.valueOf(nums[0]);

    if (nums.length == 1)
      return ans;
    if (nums.length == 2)
      return ans + "/" + String.valueOf(nums[1]);

    ans += "/(" + String.valueOf(nums[1]);
    for (int i = 2; i < nums.length; ++i)
      ans += "/" + String.valueOf(nums[i]);
    ans += ")";

    return ans;
  }
}