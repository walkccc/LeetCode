class Solution {
  public boolean isTransformable(String s, String t) {
    if (!Arrays.equals(getCount(s), getCount(t)))
      return false;

    Queue<Integer>[] positions = new Queue[10];
    for (int i = 0; i < 10; i++)
      positions[i] = new LinkedList<>();

    for (int i = 0; i < s.length(); i++)
      positions[s.charAt(i) - '0'].offer(i);

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
