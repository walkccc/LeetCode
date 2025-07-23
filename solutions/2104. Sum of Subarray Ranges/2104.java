class Solution {
  public long subArrayRanges(int[] nums) {
    Pair<int[], int[]> gt = getPrevNext(nums, (a, b) -> a < b);
    Pair<int[], int[]> lt = getPrevNext(nums, (a, b) -> a > b);
    int[] prevGt = gt.getKey();
    int[] nextGt = gt.getValue();
    int[] prevLt = lt.getKey();
    int[] nextLt = lt.getValue();
    long ans = 0;

    for (int i = 0; i < nums.length; ++i) {
      ans += (long) nums[i] * (i - prevGt[i]) * (nextGt[i] - i);
      ans -= (long) nums[i] * (i - prevLt[i]) * (nextLt[i] - i);
    }

    return ans;
  }

  // Returns `prev` and `next`, that store the indices of the nearest numbers
  // that are smaller or larger than the current number depending on `op`.
  private Pair<int[], int[]> getPrevNext(int[] nums, BiFunction<Integer, Integer, Boolean> op) {
    final int n = nums.length;
    int[] prev = new int[n];
    int[] next = new int[n];
    Arrays.fill(prev, -1);
    Arrays.fill(next, n);
    Deque<Integer> stack = new ArrayDeque<>();
    for (int i = 0; i < n; ++i) {
      while (!stack.isEmpty() && op.apply(nums[stack.peek()], nums[i]))
        next[stack.pop()] = i;
      if (!stack.isEmpty())
        prev[i] = stack.peek();
      stack.push(i);
    }
    return new Pair<>(prev, next);
  }
}
