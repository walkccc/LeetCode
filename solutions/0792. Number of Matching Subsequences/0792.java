class Solution {
  public int numMatchingSubseq(String S, String[] words) {
    for (String word : words)
      insert(word);

    return dfs(S, 0, root);
  }

  private class TrieNode {
    private TrieNode[] children = new TrieNode[26];
    private int count = 0;
  }

  private TrieNode root = new TrieNode();

  private void insert(String word) {
    TrieNode node = root;
    for (char c : word.toCharArray()) {
      int index = c - 'a';
      if (node.children[index] == null)
        node.children[index] = new TrieNode();
      node = node.children[index];
    }
    ++node.count;
  }

  private int dfs(String S, int s, TrieNode node) {
    int ans = node.count;

    if (s >= S.length())
      return ans;

    for (int i = 0; i < 26; ++i)
      if (node.children[i] != null) {
        int index = S.indexOf(i + 'a', s);
        if (index != -1)
          ans += dfs(S, index + 1, node.children[i]);
      }

    return ans;
  }
}