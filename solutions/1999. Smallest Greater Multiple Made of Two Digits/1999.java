class Solution {
  public int findInteger(int k, int digit1, int digit2) {
    final int minDigit = Math.min(digit1, digit2);
    final int maxDigit = Math.max(digit1, digit2);
    final int[] digits =
        minDigit == maxDigit ? new int[] {minDigit} : new int[] {minDigit, maxDigit};
    Queue<Integer> q = new ArrayDeque<>();

    for (final int digit : digits)
      q.offer(digit);

    while (!q.isEmpty()) {
      final int u = q.poll();
      if (u > k && u % k == 0)
        return u;
      if (u == 0)
        continue;
      for (final int digit : digits) {
        final long nextNum = u * 10L + digit;
        if (nextNum > Integer.MAX_VALUE)
          continue;
        q.offer((int) nextNum);
      }
    }

    return -1;
  }
}
