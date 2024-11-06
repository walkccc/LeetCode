class Solution {
  public int[] sortEvenOdd(int[] nums) {
    final int n = nums.length;
    int[] ans = new int[n];
    int[] evenCount = new int[101];
    int[] oddCount = new int[101];

    for (int i = 0; i < n; ++i)
      if (i % 2 == 1)
        ++oddCount[nums[i]];
      else
        ++evenCount[nums[i]];

    int ansIndex = 0;
    for (int i = 1; i < 101; ++i)
      while (evenCount[i]-- > 0) {
        ans[ansIndex] = i;
        ansIndex += 2;
      }

    ansIndex = 1;
    for (int i = 100; i > 0; --i)
      while (oddCount[i]-- > 0) {
        ans[ansIndex] = i;
        ansIndex += 2;
      }

    return ans;
  }
}
