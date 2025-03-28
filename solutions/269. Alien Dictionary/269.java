class Solution {
  public String alienOrder(String[] words) {
    Map<Character, Set<Character>> graph = new HashMap<>();
    int[] inDegrees = new int[26];
    buildGraph(graph, words, inDegrees);
    return topology(graph, inDegrees);
  }

  private void buildGraph(Map<Character, Set<Character>> graph, String[] words, int[] inDegrees) {
    // Create a node for each character in each word.
    for (final String word : words)
      for (final char c : word.toCharArray())
        graph.putIfAbsent(c, new HashSet<>());

    for (int i = 1; i < words.length; ++i) {
      final String first = words[i - 1];
      final String second = words[i];
      final int length = Math.min(first.length(), second.length());
      for (int j = 0; j < length; ++j) {
        final char u = first.charAt(j);
        final char v = second.charAt(j);
        if (u != v) {
          if (!graph.get(u).contains(v)) {
            graph.get(u).add(v);
            ++inDegrees[v - 'a'];
          }
          break; // The order of characters after this are meaningless.
        }
        // e.g. first = "ab", second = "a" -> invalid
        if (j == length - 1 && first.length() > second.length()) {
          graph.clear();
          return;
        }
      }
    }
  }

  private String topology(Map<Character, Set<Character>> graph, int[] inDegrees) {
    StringBuilder sb = new StringBuilder();
    Queue<Character> q = graph.keySet()
                             .stream()
                             .filter(c -> inDegrees[c - 'a'] == 0)
                             .collect(Collectors.toCollection(ArrayDeque::new));

    while (!q.isEmpty()) {
      final char u = q.poll();
      sb.append(u);
      for (final char v : graph.get(u))
        if (--inDegrees[v - 'a'] == 0)
          q.offer(v);
    }

    // e.g. words = ["z", "x", "y", "x"]
    return sb.length() == graph.size() ? sb.toString() : "";
  }
}
