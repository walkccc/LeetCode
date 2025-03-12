class Solution {
  // Similar to 2104. Sum of Subarray Ranges
  public long minMaxSubarraySum(int[] nums, int k) {
    Pair<int[], int[]> gt = getPrevNext(nums, (a, b) -> a < b);
    Pair<int[], int[]> lt = getPrevNext(nums, (a, b) -> a > b);
    int[] prevGt = gt.getKey();
    int[] nextGt = gt.getValue();
    int[] prevLt = lt.getKey();
    int[] nextLt = lt.getValue();
    return subarraySum(nums, k, prevGt, nextGt) + subarraySum(nums, k, prevLt, nextLt);
  }

  // Returns the sum of all subarrays with a size <= k, The `prev` and `next`
  // arrays are used to store the indices of the nearest numbers that are
  // smaller or larger than the current number, respectively.
  private long subarraySum(int[] nums, int k, int[] prev, int[] next) {
    long res = 0;
    for (int i = 0; i < nums.length; ++i) {
      final int l = Math.min(i - prev[i], k);
      final int r = Math.min(next[i] - i, k);
      final int extra = Math.max(0, l + r - 1 - k);
      res += (long) nums[i] * (l * r - extra * (extra + 1) / 2);
    }
    return res;
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
