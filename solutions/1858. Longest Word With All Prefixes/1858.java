class TrieNode {
  public TrieNode[] children = new TrieNode[26];
  public boolean isWord = false;
}

class Solution {
  public String longestWord(String[] words) {
    String ans = "";

    for (final String word : words)
      insert(word);

    for (final String word : words) {
      if (!allPrefixed(word))
        continue;
      if (ans.length() < word.length() ||
          (ans.length() == word.length() && ans.compareTo(word) > 0))
        ans = word;
    }

    return ans;
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

  private boolean allPrefixed(final String word) {
    TrieNode node = root;
    for (final char c : word.toCharArray()) {
      final int i = c - 'a';
      node = node.children[i];
      if (!node.isWord)
        return false;
    }
    return true;
  }
}
