class TrieNode {
  public TrieNode[] children = new TrieNode[26];
  public boolean isWord = false;
}

class StreamChecker {
  public StreamChecker(String[] words) {
    for (final String word : words)
      insert(word);
  }

  public boolean query(char letter) {
    letters.append(letter);
    TrieNode node = root;

    for (int i = letters.length() - 1; i >= 0; --i) {
      final int index = letters.charAt(i) - 'a';
      if (node.children[index] == null)
        return false;
      node = node.children[index];
      if (node.isWord)
        return true;
    }

    return false;
  }

  private TrieNode root = new TrieNode();
  private StringBuilder letters = new StringBuilder();

  private void insert(final String word) {
    TrieNode node = root;
    for (int i = word.length() - 1; i >= 0; --i) {
      final int index = word.charAt(i) - 'a';
      if (node.children[index] == null)
        node.children[index] = new TrieNode();
      node = node.children[index];
    }
    node.isWord = true;
  }
}
