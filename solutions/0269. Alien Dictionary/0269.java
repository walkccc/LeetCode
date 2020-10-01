class Solution {
  public String alienOrder(String[] words) {
    int[] inDegree = new int[26];
    Map<Character, Set<Character>> graph = new HashMap<>();

    buildGraph(words, inDegree, graph);

    return bfs(inDegree, graph);
  }

  private void buildGraph(final String[] words, int[] inDegree, Map<Character, Set<Character>> graph) {
    // create node for each character in each word
    for (final String word : words)
      for (final char c : word.toCharArray())
        graph.putIfAbsent(c, new HashSet<>());

    for (int i = 1; i < words.length; ++i) {
      final String first = words[i - 1];
      final String second = words[i];
      final int length = Math.min(first.length(), second.length());
      for (int j = 0; j < length; ++j) {
        final char out = first.charAt(j);
        final char in = second.charAt(j);
        if (out != in) {
          if (!graph.get(out).contains(in)) {
            graph.get(out).add(in);
            ++inDegree[in - 'a'];
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

  private String bfs(int[] inDegree, Map<Character, Set<Character>> graph) {
    StringBuilder sb = new StringBuilder();
    Queue<Character> q = new LinkedList<>();

    for (final char c : graph.keySet())
      if (inDegree[c - 'a'] == 0)
        q.offer(c);

    while (!q.isEmpty()) {
      final char out = q.poll();
      sb.append(out);
      for (final char in : graph.get(out))
        if (--inDegree[in - 'a'] == 0)
          q.offer(in);
    }

    return sb.length() == graph.size() ? sb.toString() : "";
  }
}