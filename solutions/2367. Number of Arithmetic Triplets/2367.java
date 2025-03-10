class Solution {
  public int arithmeticTriplets(int[] nums, int diff) {
    final int MAX = 200;
    int ans = 0;
    boolean[] count = new boolean[MAX + 1];

    for (final int num : nums) {
      if (num >= 2 * diff && count[num - diff] && count[num - 2 * diff])
        ++ans;
      count[num] = true;
    }

    return ans;
  }
}
