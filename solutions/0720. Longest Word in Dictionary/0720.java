class TrieNode {
  public TrieNode[] children = new TrieNode[26];
  public String word;
}

class Solution {
  public String longestWord(String[] words) {
    for (final String word : words)
      insert(word);
    return longestWordFrom(root);
  }

  private TrieNode root = new TrieNode();

  private void insert(final String word) {
    TrieNode node = root;
    for (char c : word.toCharArray()) {
      final int i = c - 'a';
      if (node.children[i] == null)
        node.children[i] = new TrieNode();
      node = node.children[i];
    }
    node.word = word;
  }

  private String longestWordFrom(TrieNode node) {
    String ans = node.word == null ? "" : node.word;

    for (TrieNode child : node.children)
      if (child != null && child.word != null) {
        String childWord = longestWordFrom(child);
        if (childWord.length() > ans.length())
          ans = childWord;
      }

    return ans;
  }
}
