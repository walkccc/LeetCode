class TrieNode {
  public TrieNode[] children = new TrieNode[26];
  public int prefixCount = 0;
  public int wordCount = 0;
}

class Trie {
  public void insert(String word) {
    TrieNode node = root;
    for (final char c : word.toCharArray()) {
      final int i = c - 'a';
      if (node.children[i] == null)
        node.children[i] = new TrieNode();
      node = node.children[i];
      ++node.prefixCount;
    }
    ++node.wordCount;
  }

  public int countWordsEqualTo(String word) {
    TrieNode node = find(word);
    return node == null ? 0 : node.wordCount;
  }

  public int countWordsStartingWith(String prefix) {
    TrieNode node = find(prefix);
    return node == null ? 0 : node.prefixCount;
  }

  public void erase(String word) {
    TrieNode node = root;
    for (final char c : word.toCharArray()) {
      final int i = c - 'a';
      node = node.children[i];
      --node.prefixCount;
    }
    --node.wordCount;
  }

  private TrieNode root = new TrieNode();

  private TrieNode find(final String s) {
    TrieNode node = root;
    for (final char c : s.toCharArray()) {
      final int i = c - 'a';
      if (node.children[i] == null)
        return null;
      node = node.children[i];
    }
    return node;
  }
}
