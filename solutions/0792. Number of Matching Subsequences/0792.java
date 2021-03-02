class TrieNode {
  public TrieNode[] children = new TrieNode[26];
  public int count = 0;
}

class Solution {
  public int numMatchingSubseq(String S, String[] words) {
    for (final String word : words)
      insert(word);

    return dfs(S, 0, root);
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

  private int dfs(final String S, int s, TrieNode node) {
    int ans = node.count;

    if (s >= S.length())
      return ans;

    for (int i = 0; i < 26; ++i)
      if (node.children[i] != null) {
        final int index = S.indexOf('a' + i, s);
        if (index != -1)
          ans += dfs(S, index + 1, node.children[i]);
      }

    return ans;
  }
}
