class TrieNode {
  public TrieNode[] children = new TrieNode[26];
  public boolean isWord = false;
}

class MagicDictionary {
  public void buildDict(String[] dict) {
    for (final String word : dict)
      insert(word);
  }

  public boolean search(String word) {
    TrieNode node = root;
    for (int i = 0; i < word.length(); ++i) {
      final char c = word.charAt(i);
      for (int j = 0; j < 26; ++j) {
        if ('a' + j == c)
          continue; // current branch exists
        if (node.children[j] == null)
          continue; // no branch j
        if (find(word, i + 1, node.children[j]))
          return true;
      }
      if (node.children[c - 'a'] == null)
        return false;
      node = node.children[c - 'a'];
    }
    return false;
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
    node.isWord = true;
  }

  private boolean find(final String word, int s, TrieNode node) {
    for (int i = s; i < word.length(); ++i) {
      final int index = word.charAt(i) - 'a';
      if (node.children[index] == null)
        return false;
      node = node.children[index];
    }
    return node.isWord;
  }
}
