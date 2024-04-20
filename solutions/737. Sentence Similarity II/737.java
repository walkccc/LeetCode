class Solution {
  public boolean areSentencesSimilarTwo(String[] words1, String[] words2,
                                        List<List<String>> pairs) {
    if (words1.length != words2.length)
      return false;

    // graph[key] := all the similar words of key
    Map<String, Set<String>> graph = new HashMap<>();

    for (List<String> pair : pairs) {
      graph.putIfAbsent(pair.get(0), new HashSet<>());
      graph.putIfAbsent(pair.get(1), new HashSet<>());
      graph.get(pair.get(1)).add(pair.get(0));
      graph.get(pair.get(0)).add(pair.get(1));
    }

    for (int i = 0; i < words1.length; ++i) {
      if (words1[i].equals(words2[i]))
        continue;
      if (!graph.containsKey(words1[i]))
        return false;
      if (!dfs(graph, words1[i], words2[i], new HashSet<>()))
        return false;
    }

    return true;
  }

  private boolean dfs(Map<String, Set<String>> graph, final String source, final String target,
                      Set<String> seen) {
    if (graph.get(source).contains(target))
      return true;

    seen.add(source);

    for (final String child : graph.get(source)) {
      if (seen.contains(child))
        continue;
      if (dfs(graph, child, target, seen))
        return true;
    }

    return false;
  }
}
