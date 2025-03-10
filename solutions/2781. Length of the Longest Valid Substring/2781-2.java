class TrieNode {
  public TrieNode[] children = new TrieNode[26];
  public boolean isWord = false;
}

class Trie {
  public void insert(String word) {
    TrieNode node = root;
    for (final char c : word.toCharArray()) {
      final int i = c - 'a';
      if (node.children[i] == null)
        node.children[i] = new TrieNode();
      node = node.children[i];
    }
    node.isWord = true;
  }

  public boolean search(String word, int l, int r) {
    TrieNode node = root;
    for (int j = l; j <= r; ++j) {
      final int i = word.charAt(j) - 'a';
      if (node.children[i] == null)
        return false;
      node = node.children[i];
    }
    return node.isWord;
  }

  private TrieNode root = new TrieNode();
}

class Solution {
  public int longestValidSubstring(String word, List<String> forbidden) {
    int ans = 0;
    Trie trie = new Trie();

    for (final String s : forbidden)
      trie.insert(s);

    // r is the rightmost index to make word[l..r] a valid substring.
    int r = word.length() - 1;
    for (int l = word.length() - 1; l >= 0; --l) {
      for (int end = l; end < Math.min(l + 10, r + 1); ++end)
        if (trie.search(word, l, end)) {
          r = end - 1;
          break;
        }
      ans = Math.max(ans, r - l + 1);
    }

    return ans;
  }
}
