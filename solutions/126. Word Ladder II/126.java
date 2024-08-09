class Solution {
  public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
    Set<String> wordSet = new HashSet<>(wordList);
    if (!wordSet.contains(endWord))
      return new ArrayList<>();

    // {"hit": ["hot"], "hot": ["dot", "lot"], ...}
    Map<String, List<String>> graph = new HashMap<>();

    // Build the graph from the beginWord to the endWord.
    if (!bfs(beginWord, endWord, wordSet, graph))
      return new ArrayList<>();

    List<List<String>> ans = new ArrayList<>();
    List<String> path = new ArrayList<>(Arrays.asList(beginWord));
    dfs(graph, beginWord, endWord, path, ans);
    return ans;
  }

  private boolean bfs(final String beginWord, final String endWord, Set<String> wordSet,
                      Map<String, List<String>> graph) {
    Set<String> currentLevelWords = new HashSet<>();
    currentLevelWords.add(beginWord);
    boolean reachEndWord = false;

    while (!currentLevelWords.isEmpty()) {
      for (final String word : currentLevelWords)
        wordSet.remove(word);
      Set<String> nextLevelWords = new HashSet<>();
      for (final String parent : currentLevelWords) {
        graph.putIfAbsent(parent, new ArrayList<>());
        for (final String child : getChildren(parent, wordSet)) {
          if (wordSet.contains(child)) {
            nextLevelWords.add(child);
            graph.get(parent).add(child);
          }
          if (child.equals(endWord))
            reachEndWord = true;
        }
      }
      if (reachEndWord)
        return true;
      currentLevelWords = nextLevelWords;
    }

    return false;
  }

  private List<String> getChildren(final String parent, Set<String> wordSet) {
    List<String> children = new ArrayList<>();
    StringBuilder sb = new StringBuilder(parent);

    for (int i = 0; i < sb.length(); ++i) {
      final char cache = sb.charAt(i);
      for (char c = 'a'; c <= 'z'; ++c) {
        if (c == cache)
          continue;
        sb.setCharAt(i, c);
        final String child = sb.toString();
        if (wordSet.contains(child))
          children.add(child);
      }
      sb.setCharAt(i, cache);
    }

    return children;
  }

  private void dfs(Map<String, List<String>> graph, final String word, final String endWord,
                   List<String> path, List<List<String>> ans) {
    if (word.equals(endWord)) {
      ans.add(new ArrayList<>(path));
      return;
    }
    if (!graph.containsKey(word))
      return;

    for (final String child : graph.get(word)) {
      path.add(child);
      dfs(graph, child, endWord, path, ans);
      path.remove(path.size() - 1);
    }
  }
}
