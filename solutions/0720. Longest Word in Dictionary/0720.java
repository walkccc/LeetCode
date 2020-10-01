class Solution {
  public String longestWord(String[] words) {
    for (final String word : words)
      insert(word);

    return dfs(root);
  }

  private class TrieNode {
    private TrieNode[] children = new TrieNode[26];
    private String word;
  }

  private TrieNode root = new TrieNode();

  private void insert(final String word) {
    TrieNode node = root;
    for (char c : word.toCharArray()) {
      int index = c - 'a';
      if (node.children[index] == null)
        node.children[index] = new TrieNode();
      node = node.children[index];
    }
    node.word = word;
  }

  private String dfs(TrieNode node) {
    String ans = node.word == null ? "" : node.word;

    for (TrieNode child : node.children)
      if (child != null && child.word != null && child.word.length() > 0) {
        String childWord = dfs(child);
        if (childWord.length() > ans.length())
          ans = childWord;
      }

    return ans;
  }
}