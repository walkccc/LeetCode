class Solution {
  // Same as 2865. Beautiful Towers I
  public long maximumSumOfHeights(List<Integer> maxHeights) {
    final int n = maxHeights.size();
    long[] maxSum = new long[n]; // maxSum[i] := the maximum sum with peak i

    Deque<Integer> stack = new ArrayDeque<>(List.of(-1));
    long sum = 0;

    for (int i = 0; i < n; ++i) {
      sum = process(stack, maxHeights, i, sum);
      maxSum[i] = sum;
    }

    stack = new ArrayDeque<>(List.of(n));
    sum = 0;

    for (int i = n - 1; i >= 0; --i) {
      sum = process(stack, maxHeights, i, sum);
      maxSum[i] += sum - maxHeights.get(i);
    }

    return Arrays.stream(maxSum).max().getAsLong();
  }

  private long process(Deque<Integer> stack, List<Integer> maxHeights, int i, long sum) {
    while (stack.size() > 1 && maxHeights.get(stack.peek()) > maxHeights.get(i)) {
      int j = stack.pop();
      // The last abs(j - stack.peek()) maxHeights are `maxHeights[j]`.
      sum -= (long) Math.abs(j - stack.peek()) * maxHeights.get(j);
    }
    // Put abs(i - stack.peek()) * maxHeights[i] in `maxHeights`.
    sum += (long) Math.abs(i - stack.peek()) * maxHeights.get(i);
    stack.push(i);
    return sum;
  }
}
