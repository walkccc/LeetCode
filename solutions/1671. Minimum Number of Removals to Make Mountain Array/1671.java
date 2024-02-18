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
    // tail[i] := the minimum tail of all the increasing subsequences with
    // length i + 1
    // It's easy to see that tail must be an increasing array.
    List<Integer> tail = new ArrayList<>();
    // dp[i] := the length of LIS ending in nums[i]
    int[] dp = new int[nums.length];

    for (int i = 0; i < nums.length; ++i) {
      final int num = nums[i];
      if (tail.isEmpty() || num > tail.get(tail.size() - 1))
        tail.add(num);
      else
        tail.set(firstGreaterEqual(tail, num), num);
      dp[i] = tail.size();
    }

    return dp;
  }

  private int firstGreaterEqual(List<Integer> A, int target) {
    final int i = Collections.binarySearch(A, target);
    return i < 0 ? -i - 1 : i;
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
