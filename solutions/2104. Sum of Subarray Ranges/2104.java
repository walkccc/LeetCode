class Solution {
  public long subArrayRanges(int[] nums) {
    return subarraySum(nums, '<') - subarraySum(nums, '>');
  }

  private long subarraySum(int[] A, char op) {
    final int n = A.length;
    long ans = 0;
    int[] prev = new int[n];
    int[] next = new int[n];
    Deque<Integer> stack = new ArrayDeque<>();

    Arrays.fill(prev, -1);
    Arrays.fill(next, n);

    for (int i = 0; i < n; ++i) {
      while (!stack.isEmpty() && func(op, A[stack.peek()], A[i])) {
        final int index = stack.pop();
        next[index] = i;
      }
      if (!stack.isEmpty())
        prev[i] = stack.peek();
      stack.push(i);
    }

    for (int i = 0; i < n; ++i)
      ans += (long) A[i] * (i - prev[i]) * (next[i] - i);

    return ans;
  }

  private boolean func(char op, int a, int b) {
    if (op == '<')
      return a < b;
    return a > b;
  }
}
