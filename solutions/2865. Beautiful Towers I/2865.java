class Solution {
  public long maximumSumOfHeights(int[] heights) {
    final int n = heights.length;
    long[] maxSum = new long[n]; // maxSum[i] := the maximum sum with peak i

    Deque<Integer> stack = new ArrayDeque<>(List.of(-1));
    long sum = 0;

    for (int i = 0; i < n; i++) {
      sum = process(stack, heights, i, sum);
      maxSum[i] = sum;
    }

    stack = new ArrayDeque<>(List.of(n));
    sum = 0;

    for (int i = n - 1; i >= 0; i--) {
      sum = process(stack, heights, i, sum);
      maxSum[i] += sum - heights[i];
    }

    return Arrays.stream(maxSum).max().getAsLong();
  }

  private long process(Deque<Integer> stack, int[] heights, int i, long sum) {
    while (stack.size() > 1 && heights[stack.peek()] > heights[i]) {
      int j = stack.pop();
      // The last abs(j - stack.peek()) heights are `heights[j]`.
      sum -= (long) Math.abs(j - stack.peek()) * heights[j];
    }
    // Put abs(i - stack.peek()) * heights[i] in `heights`.
    sum += (long) Math.abs(i - stack.peek()) * heights[i];
    stack.push(i);
    return sum;
  }
}
