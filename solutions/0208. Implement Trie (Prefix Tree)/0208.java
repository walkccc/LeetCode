class TrieNode {
  public TrieNode[] children = new TrieNode[26];
  public boolean isWord = false;
}

class Trie {
  public void insert(String word) {
    TrieNode node = root;
    for (final char c : word.toCharArray()) {
      if (node.children[c - 'a'] == null)
        node.children[c - 'a'] = new TrieNode();
      node = node.children[c - 'a'];
    }
    node.isWord = true;
  }

  public boolean search(String word) {
    TrieNode node = find(word);
    return node != null && node.isWord;
  }

  public boolean startsWith(String prefix) {
    return find(prefix) != null;
  }

  private TrieNode root = new TrieNode();

  private TrieNode find(String prefix) {
    TrieNode node = root;
    for (final char c : prefix.toCharArray()) {
      if (node.children[c - 'a'] == null)
        return null;
      node = node.children[c - 'a'];
    }
    return node;
  }
}