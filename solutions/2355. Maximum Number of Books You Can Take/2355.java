class Solution {
  public long maximumBooks(int[] books) {
    // dp[i] := the maximum number of books we can take from books[0..i] with taking all of
    // books[i]
    long[] dp = new long[books.length];
    Deque<Integer> stack = new ArrayDeque<>(); // the possible indices we can reach

    for (int i = 0; i < books.length; ++i) {
      // We may take all of books[j], where books[j] < books[i] - (i - j).
      while (!stack.isEmpty() && books[stack.peek()] >= books[i] - (i - stack.peek()))
        stack.pop();
      // We can now take books[j + 1..i].
      final int j = stack.isEmpty() ? -1 : stack.peek();
      final int lastTook = books[i] - (i - j) + 1;
      if (lastTook > 1)
        // books[i] + (books[i] - 1) + ... + (books[i] - (i - j) + 1)
        dp[i] = (long) (books[i] + lastTook) * (i - j) / 2;
      else
        // 1 + 2 + ... + books[i]
        dp[i] = (long) books[i] * (books[i] + 1) / 2;
      if (j >= 0)
        dp[i] += dp[j];
      stack.push(i);
    }

    return Arrays.stream(dp).max().getAsLong();
  }
}
