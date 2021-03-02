class Solution {
  public String replaceWords(List<String> dict, String sentence) {
    String ans = "";

    for (final String word : dict)
      insert(word);

    final String[] words = sentence.split(" ");
    for (final String word : words)
      ans += ' ' + search(word);

    return ans.substring(1);
  }

  private class TrieNode {
    private TrieNode[] children = new TrieNode[26];
    private String word;
  }

  private TrieNode root = new TrieNode();

  private void insert(final String word) {
    TrieNode node = root;
    for (char c : word.toCharArray()) {
      int index = c - 'a';
      if (node.children[index] == null)
        node.children[index] = new TrieNode();
      node = node.children[index];
    }
    node.word = word;
  }

  private String search(final String word) {
    TrieNode node = root;
    for (char c : word.toCharArray()) {
      if (node.word != null)
        return node.word;
      int index = c - 'a';
      if (node.children[index] == null)
        return word;
      node = node.children[index];
    }
    return word;
  }
}
