class Solution {
  // Similar to 3205. Maximum Array Hopping Score I
  public long findMaximumScore(List<Integer> nums) {
    // The optimal jump is the nearest index j > i s.t. nums[j] > nums[i].
    long ans = 0;
    int mx = 0;

    for (final int num : nums) {
      ans += mx;
      mx = Math.max(mx, num);
    }

    return ans;
  }
}
