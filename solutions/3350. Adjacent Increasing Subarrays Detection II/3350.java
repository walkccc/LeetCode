class Solution {
  // Similar to 3349. Adjacent Increasing Subarrays Detection I
  public int maxIncreasingSubarrays(List<Integer> nums) {
    int ans = 0;
    int increasing = 1;
    int prevIncreasing = 0;

    for (int i = 1; i < nums.size(); ++i) {
      if (nums.get(i) > nums.get(i - 1)) {
        ++increasing;
      } else {
        prevIncreasing = increasing;
        increasing = 1;
      }
      ans = Math.max(ans, increasing / 2);
      ans = Math.max(ans, Math.min(prevIncreasing, increasing));
    }

    return ans;
  }
}
