class TrieNode {
  public TrieNode[] children = new TrieNode[26];
  public int prefixCount = 0;
  public int wordCount = 0;
}

class Trie {
  public void insert(final String word) {
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

  public int countWordsEqualTo(final String word) {
    TrieNode node = find(word);
    return node == null ? 0 : node.wordCount;
  }

  public int countWordsStartingWith(final String prefix) {
    TrieNode node = find(prefix);
    return node == null ? 0 : node.prefixCount;
  }

  public void erase(final String word) {
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
