class TrieNode {
  Map<Integer, TrieNode> children = new HashMap<>();
  int count = 0;
}

class Trie {
  public int insert(final String word) {
    final int n = word.length();
    int count = 0;
    TrieNode node = root;
    for (int i = 0; i < n; ++i) {
      final char prefix = word.charAt(i);
      final char suffix = word.charAt(n - 1 - i);
      final int key = (prefix - 'a') * 26 + (suffix - 'a');
      node.children.putIfAbsent(key, new TrieNode());
      node = node.children.get(key);
      count += node.count;
    }
    ++node.count;
    return count;
  }

  private TrieNode root = new TrieNode();
}

class Solution {
  public long countPrefixSuffixPairs(String[] words) {
    long ans = 0;
    Trie trie = new Trie();

    for (final String word : words)
      ans += trie.insert(word);

    return ans;
  }
}
