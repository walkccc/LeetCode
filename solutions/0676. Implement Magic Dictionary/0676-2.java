class TrieNode {
  public TrieNode[] children = new TrieNode[26];
  public boolean isWord = false;
}

class MagicDictionary {
  public void buildDict(String[] dictionary) {
    for (final String word : dictionary)
      insert(word);
  }

  public boolean search(String searchWord) {
    TrieNode node = root;
    for (int i = 0; i < searchWord.length(); ++i) {
      final int index = searchWord.charAt(i) - 'a';
      for (int j = 0; j < 26; ++j) {
        if (j == index)
          continue;
        TrieNode child = node.children[j];
        if (child == null)
          continue;
        // Replace the searchWord[i] with ('a' + j), then check if
        // searchWord[i + 1..n) matches `child`.
        if (find(child, searchWord, i + 1))
          return true;
      }
      if (node.children[index] == null)
        return false;
      node = node.children[index];
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

  private boolean find(TrieNode node, final String word, int s) {
    for (int i = s; i < word.length(); ++i) {
      final int index = word.charAt(i) - 'a';
      if (node.children[index] == null)
        return false;
      node = node.children[index];
    }
    return node.isWord;
  }
}
