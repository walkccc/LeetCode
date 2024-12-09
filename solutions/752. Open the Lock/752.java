class Solution {
  public int openLock(String[] deadends, String target) {
    Set<String> seen = new HashSet<>(Arrays.asList(deadends));
    if (seen.contains("0000"))
      return -1;
    if (target.equals("0000"))
      return 0;

    Queue<String> q = new ArrayDeque<>(List.of("0000"));

    for (int step = 1; !q.isEmpty(); ++step)
      for (int sz = q.size(); sz > 0; --sz) {
        StringBuilder sb = new StringBuilder(q.poll());
        for (int i = 0; i < 4; ++i) {
          final char cache = sb.charAt(i);
          // Increase the i-th digit by 1.
          sb.setCharAt(i, sb.charAt(i) == '9' ? '0' : (char) (sb.charAt(i) + 1));
          String word = sb.toString();
          if (word.equals(target))
            return step;
          if (!seen.contains(word)) {
            q.offer(word);
            seen.add(word);
          }
          sb.setCharAt(i, cache);
          // Decrease the i-th digit by 1.
          sb.setCharAt(i, sb.charAt(i) == '0' ? '9' : (char) (sb.charAt(i) - 1));
          word = sb.toString();
          if (word.equals(target))
            return step;
          if (!seen.contains(word)) {
            q.offer(word);
            seen.add(word);
          }
          sb.setCharAt(i, cache);
        }
      }

    return -1;
  }
}
