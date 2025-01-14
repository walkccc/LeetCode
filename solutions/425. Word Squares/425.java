class TrieNode {
  public TrieNode[] children = new TrieNode[26];
  public List<String> startsWith = new ArrayList<>();
}

class Trie {
  public Trie(final String[] words) {
    for (final String word : words)
      insert(word);
  }

  public List<String> findBy(final String prefix) {
    TrieNode node = root;
    for (final char c : prefix.toCharArray()) {
      final int i = c - 'a';
      if (node.children[i] == null)
        return new ArrayList<>();
      node = node.children[i];
    }
    return node.startsWith;
  }

  private TrieNode root = new TrieNode();

  private void insert(final String word) {
    TrieNode node = root;
    for (final char c : word.toCharArray()) {
      final int i = c - 'a';
      if (node.children[i] == null)
        node.children[i] = new TrieNode();
      node = node.children[i];
      node.startsWith.add(word);
    }
  }
}

class Solution {
  public List<List<String>> wordSquares(String[] words) {
    if (words.length == 0)
      return new ArrayList<>();

    final int n = words[0].length();
    List<List<String>> ans = new ArrayList<>();
    List<String> path = new ArrayList<>();
    Trie trie = new Trie(words);

    for (final String word : words) {
      path.add(word);
      dfs(trie, n, path, ans);
      path.remove(path.size() - 1);
    }

    return ans;
  }

  private void dfs(Trie trie, final int n, List<String> path, List<List<String>> ans) {
    if (path.size() == n) {
      ans.add(new ArrayList<>(path));
      return;
    }

    final String prefix = getPrefix(path);

    for (final String s : trie.findBy(prefix)) {
      path.add(s);
      dfs(trie, n, path, ans);
      path.remove(path.size() - 1);
    }
  }

  // e.g. path = ["wall",
  //              "area"]
  //    prefix =  "le.."
  private String getPrefix(List<String> path) {
    StringBuilder sb = new StringBuilder();
    final int index = path.size();
    for (final String s : path)
      sb.append(s.charAt(index));
    return sb.toString();
  }
}
