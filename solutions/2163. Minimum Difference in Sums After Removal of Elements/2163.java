class Solution {
  public long minimumDifference(int[] nums) {
    final int n = nums.length / 3;
    long ans = Long.MAX_VALUE;
    long leftSum = 0;
    long rightSum = 0;
    // The left part should be as small as possible.
    Queue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
    // The right part should be as big as possible.
    Queue<Integer> minHeap = new PriorityQueue<>();
    // minLeftSum[i] := the minimum of the sum of n nums in nums[0..i)
    long[] minLeftSum = new long[nums.length];

    for (int i = 0; i < 2 * n; ++i) {
      maxHeap.offer(nums[i]);
      leftSum += nums[i];
      if (maxHeap.size() == n + 1)
        leftSum -= maxHeap.poll();
      if (maxHeap.size() == n)
        minLeftSum[i] = leftSum;
    }

    for (int i = nums.length - 1; i >= n; --i) {
      minHeap.offer(nums[i]);
      rightSum += nums[i];
      if (minHeap.size() == n + 1)
        rightSum -= minHeap.poll();
      if (minHeap.size() == n)
        ans = Math.min(ans, minLeftSum[i - 1] - rightSum);
    }

    return ans;
  }
}
