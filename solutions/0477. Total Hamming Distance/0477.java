class Solution {
  public int totalHammingDistance(int[] nums) {
    int ans = 0;
    int mask = 1;

    for (int i = 0; i < 30; ++i) {
      final int onesCount = getCount(nums, mask);
      final int zerosCount = nums.length - onesCount;
      ans += onesCount * zerosCount;
      mask <<= 1;
    }

    return ans;
  }

  private int getCount(int[] nums, int mask) {
    int count = 0;
    for (final int num : nums)
      if ((num & mask) > 0)
        ++count;
    return count;
  }
}
