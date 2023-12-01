class Solution {
  public int maxSubarrays(int[] nums) {
    int ans = 0;
    int score = 0;

    for (final int num : nums) {
      score = score == 0 ? num : score & num;
      if (score == 0)
        ++ans;
    }

    return Math.max(1, ans);
  }
}
