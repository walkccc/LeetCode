class Solution {
  public int minMutation(String startGene, String endGene, String[] bank) {
    Set<String> bankSet = new HashSet<>(Arrays.asList(bank));
    if (!bankSet.contains(endGene))
      return -1;

    final char[] GENES = new char[] {'A', 'C', 'G', 'T'};
    Queue<String> q = new ArrayDeque<>(List.of(startGene));

    for (int step = 1; !q.isEmpty(); ++step)
      for (int sz = q.size(); sz > 0; --sz) {
        StringBuilder sb = new StringBuilder(q.poll());
        for (int j = 0; j < sb.length(); ++j) {
          final char cache = sb.charAt(j);
          for (final char c : GENES) {
            sb.setCharAt(j, c);
            final String word = sb.toString();
            if (word.equals(endGene))
              return step;
            if (bankSet.contains(word)) {
              bankSet.remove(word);
              q.offer(word);
            }
          }
          sb.setCharAt(j, cache);
        }
      }

    return -1;
  }
}
