class Solution {
  public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
    Set<String> wordSet = new HashSet<>(wordList);
    if (!wordSet.contains(endWord))
      return new ArrayList<>();

    Map<String, List<String>> parentToChildren = new HashMap<>();
    Set<String> currentLevelWords = new HashSet<>();
    currentLevelWords.add(beginWord);
    boolean isFound = false;

    while (!currentLevelWords.isEmpty()) {
      // remove words in current level
      for (final String word : currentLevelWords)
        wordSet.remove(word);
      Set<String> nextLevelWords = new HashSet<>();
      // `parent` will be used as a key in `parentToChildren`
      for (final String parent : currentLevelWords) {
        StringBuilder sb = new StringBuilder(parent);
        for (int i = 0; i < sb.length(); ++i) {
          final char cache = sb.charAt(i);
          for (char c = 'a'; c <= 'z'; ++c) {
            sb.setCharAt(i, c);
            final String child = sb.toString();
            if (wordSet.contains(child)) {
              if (child.equals(endWord))
                isFound = true;
              nextLevelWords.add(child);
              parentToChildren.computeIfAbsent(parent, k -> new ArrayList<>()).add(child);
            }
          }
          sb.setCharAt(i, cache);
        }
        currentLevelWords = nextLevelWords;
      }
      if (isFound)
        break;
    }

    if (!isFound)
      return new ArrayList<>();

    List<List<String>> ans = new ArrayList<>();
    List<String> path = new ArrayList<>(Arrays.asList(beginWord));

    dfs(parentToChildren, beginWord, endWord, path, ans);

    return ans;
  }

  // construct the ans by `parentToChildren`
  private void dfs(Map<String, List<String>> parentToChildren, final String word,
      final String endWord, List<String> path, List<List<String>> ans) {
    if (word.equals(endWord)) {
      ans.add(new ArrayList<>(path));
      return;
    }
    if (!parentToChildren.containsKey(word))
      return;

    for (final String child : parentToChildren.get(word)) {
      path.add(child);
      dfs(parentToChildren, child, endWord, path, ans);
      path.remove(path.size() - 1);
    }
  }
}
