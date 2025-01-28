class Solution {
  public List<String> generateSentences(List<List<String>> synonyms, String text) {
    Set<String> ans = new TreeSet<>();
    Map<String, List<String>> graph = new HashMap<>();
    Queue<String> q = new ArrayDeque<>(List.of(text));

    for (List<String> synonym : synonyms) {
      final String s = synonym.get(0);
      final String t = synonym.get(1);
      graph.putIfAbsent(s, new ArrayList<>());
      graph.putIfAbsent(t, new ArrayList<>());
      graph.get(s).add(t);
      graph.get(t).add(s);
    }

    while (!q.isEmpty()) {
      final String u = q.poll();
      ans.add(u);
      String[] words = u.split("\\s");
      for (int i = 0; i < words.length; ++i)
        for (final String synonym : graph.getOrDefault(words[i], new ArrayList<>())) {
          // Replace words[i] with its synonym.
          words[i] = synonym;
          final String newText = String.join(" ", words);
          if (!ans.contains(newText))
            q.offer(newText);
        }
    }

    return new ArrayList<>(ans);
  }
}
