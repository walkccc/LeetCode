class Solution {
  public String alienOrder(String[] words) {
    Map<Character, Set<Character>> graph = new HashMap<>();
    int[] inDegree = new int[26];
    buildGraph(graph, words, inDegree);
    return topology(graph, inDegree);
  }

  private void buildGraph(Map<Character, Set<Character>> graph, String[] words, int[] inDegree) {
    // create node for each character in each word
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
            ++inDegree[v - 'a'];
          }
          break; // later characters' order are meaningless
        }
        // first = "ab", second = "a" -> invalid
        if (j == length - 1 && first.length() > second.length()) {
          graph.clear();
          return;
        }
      }
    }
  }

  private String topology(Map<Character, Set<Character>> graph, int[] inDegree) {
    StringBuilder sb = new StringBuilder();
    Queue<Character> q = graph.keySet()
                             .stream()
                             .filter(c -> inDegree[c - 'a'] == 0)
                             .collect(Collectors.toCollection(ArrayDeque::new));

    while (!q.isEmpty()) {
      final char u = q.poll();
      sb.append(u);
      for (final char v : graph.get(u))
        if (--inDegree[v - 'a'] == 0)
          q.offer(v);
    }

    // words = ["z", "x", "y", "x"]
    return sb.length() == graph.size() ? sb.toString() : "";
  }
}
