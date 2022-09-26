class Solution {
  // very similar to 907. Sum of Subarray Minimums
  public int validSubarraySize(int[] nums, int threshold) {
    final int n = nums.length;
    long ans = 0;
    // prev[i] := index k s.t. nums[k] is the prev min in nums[:i]
    int[] prev = new int[n];
    // next[i] := index k s.t. nums[k] is the next min in nums[i + 1:]
    int[] next = new int[n];
    Deque<Integer> stack = new ArrayDeque<>();

    Arrays.fill(prev, -1);
    Arrays.fill(next, n);

    for (int i = 0; i < nums.length; ++i) {
      while (!stack.isEmpty() && nums[stack.peek()] > nums[i]) {
        final int index = stack.pop();
        next[index] = i;
      }
      if (!stack.isEmpty())
        prev[i] = stack.peek();
      stack.push(i);
    }

    for (int i = 0; i < n; ++i) {
      // # of nums in subarray containing nums[i] >= nums[i]
      final int k = (i - prev[i]) + (next[i] - i) - 1;
      if (nums[i] > threshold / (double) k)
        return k;
    }

    return -1;
  }
}
