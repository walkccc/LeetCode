class Solution {
  public int minMutation(String start, String end, String[] bank) {
    Set<String> bankSet = new HashSet<>(Arrays.asList(bank));
    if (!bankSet.contains(end))
      return -1;

    int ans = 0;
    Queue<String> q = new ArrayDeque<>(Arrays.asList(start));

    while (!q.isEmpty()) {
      ++ans;
      for (int sz = q.size(); sz > 0; --sz) {
        StringBuilder sb = new StringBuilder(q.poll());
        for (int j = 0; j < sb.length(); ++j) {
          final char cache = sb.charAt(j);
          for (final char c : new char[] {'A', 'C', 'G', 'T'}) {
            sb.setCharAt(j, c);
            final String word = sb.toString();
            if (word.equals(end))
              return ans;
            if (bankSet.contains(word)) {
              bankSet.remove(word);
              q.offer(word);
            }
          }
          sb.setCharAt(j, cache);
        }
      }
    }

    return -1;
  }
}
