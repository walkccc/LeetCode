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

  // Similar to 300. Longest Increasing Subsequence
  private int[] lengthOfLIS(int[] nums) {
    // tails[i] := the minimum tail of all the increasing subsequences with
    // length i + 1
    List<Integer> tails = new ArrayList<>();
    // dp[i] := the length of LIS ending in nums[i]
    int[] dp = new int[nums.length];
    for (int i = 0; i < nums.length; ++i) {
      final int num = nums[i];
      if (tails.isEmpty() || num > tails.get(tails.size() - 1))
        tails.add(num);
      else
        tails.set(firstGreaterEqual(tails, num), num);
      dp[i] = tails.size();
    }
    return dp;
  }

  private int firstGreaterEqual(List<Integer> arr, int target) {
    final int i = Collections.binarySearch(arr, target);
    return i < 0 ? -i - 1 : i;
  }

  private int[] reversed(int[] nums) {
    int[] arr = nums.clone();
    int l = 0;
    int r = nums.length - 1;
    while (l < r)
      swap(arr, l++, r--);
    return arr;
  }

  private void swap(int[] arr, int i, int j) {
    final int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
}
