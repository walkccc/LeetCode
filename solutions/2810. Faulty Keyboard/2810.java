class Solution {
  public String finalString(String s) {
    StringBuilder sb = new StringBuilder();
    Deque<Character> dq = new ArrayDeque<>();
    boolean inversed = false;

    for (final char c : s.toCharArray())
      if (c == 'i')
        inversed = !inversed;
      else if (inversed)
        dq.addFirst(c);
      else
        dq.addLast(c);

    while (!dq.isEmpty())
      sb.append(dq.pollFirst());

    return inversed ? sb.reverse().toString() : sb.toString();
  }
}
