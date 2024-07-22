class Solution {
  public long maximumSumOfHeights(List<Integer> maxHeights) {
    final int n = maxHeights.size();
    long[] maxSum = new long[n]; // maxSum[i] := the maximum sum with peak i

    Deque<Integer> stack = new ArrayDeque<>(Arrays.asList(-1));
    stack.push(-1);
    long summ = 0;

    for (int i = 0; i < n; ++i) {
      summ = process(stack, maxHeights, i, summ);
      maxSum[i] = summ;
    }

    stack = new ArrayDeque<>(Arrays.asList(n));
    summ = 0;

    for (int i = n - 1; i >= 0; --i) {
      summ = process(stack, maxHeights, i, summ);
      maxSum[i] += summ - maxHeights.get(i);
    }

    return Arrays.stream(maxSum).max().getAsLong();
  }

  private long process(Deque<Integer> stack, List<Integer> maxHeights, int i, long summ) {
    while (stack.size() > 1 && maxHeights.get(stack.peek()) > maxHeights.get(i)) {
      final int j = stack.pop();
      // The last abs(j - stack.peek()) heights are maxHeights.get(j).
      summ -= Math.abs(j - stack.peek()) * (long) maxHeights.get(j);
    }
    // Put abs(i - stack.peek()) `maxHeights.get(i)` in heights.
    summ += Math.abs(i - stack.peek()) * (long) maxHeights.get(i);
    stack.push(i);
    return summ;
  }
}
