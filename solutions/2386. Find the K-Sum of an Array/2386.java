class Solution {
  public long kSum(int[] nums, int k) {
    final long maxSum = getMaxSum(nums);
    final int[] absNums = getAbsNums(nums);
    long ans = maxSum;
    // (the next maximum sum, the next index i)
    Queue<Pair<Long, Integer>> maxHeap =
        new PriorityQueue<>((a, b) -> Long.compare(b.getKey(), a.getKey()));
    maxHeap.offer(new Pair<>(maxSum - absNums[0], 0));

    for (int j = 0; j < k - 1; ++j) {
      Pair<Long, Integer> pair = maxHeap.poll();
      final long nextMaxSum = pair.getKey();
      final int i = pair.getValue();
      ans = nextMaxSum;
      if (i + 1 < absNums.length) {
        maxHeap.offer(new Pair<>(nextMaxSum - absNums[i + 1], i + 1));
        maxHeap.offer(new Pair<>(nextMaxSum - absNums[i + 1] + absNums[i], i + 1));
      }
    }

    return ans;
  }

  private long getMaxSum(int[] nums) {
    long maxSum = 0;
    for (final int num : nums)
      if (num > 0)
        maxSum += num;
    return maxSum;
  }

  private int[] getAbsNums(int[] nums) {
    for (int i = 0; i < nums.length; ++i)
      nums[i] = Math.abs(nums[i]);
    Arrays.sort(nums);
    return nums;
  }
}
