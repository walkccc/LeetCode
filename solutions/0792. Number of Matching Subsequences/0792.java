class TrieNode {
  public TrieNode[] children = new TrieNode[26];
  public int count = 0;
}

class Solution {
  public int numMatchingSubseq(String s, String[] words) {
    for (final String word : words)
      insert(word);
    return dfs(s, 0, root);
  }

  private TrieNode root = new TrieNode();

  private void insert(final String word) {
    TrieNode node = root;
    for (final char c : word.toCharArray()) {
      final int i = c - 'a';
      if (node.children[i] == null)
        node.children[i] = new TrieNode();
      node = node.children[i];
    }
    ++node.count;
  }

  private int dfs(final String s, int i, TrieNode node) {
    int ans = node.count;
    if (i >= s.length())
      return ans;

    for (int j = 0; j < 26; ++j)
      if (node.children[j] != null) {
        final int index = s.indexOf('a' + j, i);
        if (index != -1)
          ans += dfs(s, index + 1, node.children[j]);
      }

    return ans;
  }
}
