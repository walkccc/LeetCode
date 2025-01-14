class Solution {
  public int findKOr(int[] nums, int k) {
    final int kMaxBit = 30;
    int ans = 0;

    for (int i = 0; i <= kMaxBit; ++i) {
      final int finalI = i;
      final int count = (int) Arrays.stream(nums)
                            .filter(num -> (num >> finalI & 1) == 1) //
                            .count();
      if (count >= k)
        ans += Math.pow(2, i);
    }

    return ans;
  }
}
