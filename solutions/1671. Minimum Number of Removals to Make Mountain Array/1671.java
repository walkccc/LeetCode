class Solution {
  public int minimumMountainRemovals(int[] nums) {
    int[] l = lengthOfLIS(nums);
    int[] r = reversed(lengthOfLIS(reversed(nums)));
    int maxMountainSeq = 0;

    for (int i = 0; i < nums.length; ++i)
      if (l[i] > 1 && r[i] > 1)
        maxMountainSeq = Math.max(maxMountainSeq, l[i] + r[i] - 1);

    return nums.length - maxMountainSeq;
  }

  private int[] lengthOfLIS(int[] nums) {
    int maxLength = 0;
    // tail[i] := the minimum tail of all increasing subseqs with length i + 1
    // it's easy to see that tail must be an increasing array
    int[] tail = new int[nums.length];

    // dp[i] := length of LIS ending at nums[i]
    int[] dp = new int[nums.length];

    for (int i = 0; i < nums.length; ++i) {
      final int num = nums[i];
      // find the first index k in tail[0..maxLength) s.t. tail[k] >= num
      int k = Arrays.binarySearch(tail, 0, maxLength, num);
      // k = -(insertion point) - 1
      // insertion point = -(k + 1)
      if (k < 0)
        k = -(k + 1);
      tail[k] = num;
      // if didn't find any number in tail[0..maxLength) that is >= num, it means we
      // can append num in the current increasing subsequence
      if (k == maxLength)
        ++maxLength;
      dp[i] = maxLength;
    }

    return dp;
  }

  private int[] reversed(int[] nums) {
    int[] A = nums.clone();
    int l = 0;
    int r = nums.length - 1;

    while (l < r)
      swap(A, l++, r--);

    return A;
  }

  private void swap(int[] A, int i, int j) {
    final int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
  }
}
