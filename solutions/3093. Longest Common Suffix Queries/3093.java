class TrieNode {
  public TrieNode[] children = new TrieNode[26];
  public boolean isWord = false;
  public int length = Integer.MAX_VALUE;
  public int index = -1;
}

class Solution {
  public int[] stringIndices(String[] wordsContainer, String[] wordsQuery) {
    int[] ans = new int[wordsQuery.length];
    int minIndex = 0;

    for (int i = 0; i < wordsContainer.length; ++i) {
      insert(wordsContainer[i], i);
      if (wordsContainer[i].length() < wordsContainer[minIndex].length())
        minIndex = i;
    }

    for (int i = 0; i < wordsQuery.length; ++i) {
      final int index = search(wordsQuery[i]);
      ans[i] = index == -1 ? minIndex : index;
    }

    return ans;
  }

  private TrieNode root = new TrieNode();

  private void insert(final String word, int index) {
    TrieNode node = root;
    for (int i = word.length() - 1; i >= 0; --i) {
      final int index = word.charAt(i) - 'a';
      if (node.children[index] == null)
        node.children[index] = new TrieNode();
      node = node.children[index];
      if (node.length > word.length()) {
        node.length = word.length();
        node.index = index;
      }
    }
  }

  private int search(final String word) {
    TrieNode node = root;
    for (int i = word.length() - 1; i >= 0; --i) {
      final int index = word.charAt(i) - 'a';
      if (node.children[index] == null)
        return node.index;
      node = node.children[index];
    }
    return node.index;
  }
}
