class Solution {
  public boolean isTransformable(String s, String t) {
    if (!Arrays.equals(getCount(s), getCount(t)))
      return false;

    Queue<Integer>[] positions = new Queue[10];
    for (int i = 0; i < 10; i++)
      positions[i] = new LinkedList<>();

    for (int i = 0; i < s.length(); i++)
      positions[s.charAt(i) - '0'].offer(i);

    // For each digit in `t`, check if we can put this digit in `s` at the same
    // position as `t`. Ensure that all the left digits are equal to or greater
    // than it. This is because the only operation we can perform is sorting in
    // ascending order. If there is a digit to the left that is smaller than it,
    // we can never move it to the same position as in `t`. However, if all the
    // digits to its left are equal to or greater than it, we can move it one
    // position to the left until it reaches the same position as in `t`.
    for (final char c : t.toCharArray()) {
      final int d = c - '0';
      final int front = positions[d].poll();
      for (int smaller = 0; smaller < d; ++smaller)
        if (!positions[smaller].isEmpty() && positions[smaller].peek() < front)
          return false;
    }

    return true;
  }

  private int[] getCount(String s) {
    int[] count = new int[10];
    for (char c : s.toCharArray())
      count[c - '0']++;
    return count;
  }
}
