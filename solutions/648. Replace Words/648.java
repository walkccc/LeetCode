class TrieNode {
  private TrieNode[] children = new TrieNode[26];
  private String word;
}

class Solution {
  public String replaceWords(List<String> dictionary, String sentence) {
    StringBuilder sb = new StringBuilder();

    for (final String word : dictionary)
      insert(word);

    final String[] words = sentence.split(" ");
    for (final String word : words)
      sb.append(' ').append(search(word));

    return sb.substring(1).toString();
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

  private String search(final String word) {
    TrieNode node = root;
    for (char c : word.toCharArray()) {
      if (node.word != null)
        return node.word;
      final int i = c - 'a';
      if (node.children[i] == null)
        return word;
      node = node.children[i];
    }
    return word;
  }
}
