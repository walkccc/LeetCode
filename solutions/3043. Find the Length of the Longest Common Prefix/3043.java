class TrieNode {
  public TrieNode[] children = new TrieNode[10];
}

class Trie {
  public void insert(final String word) {
    TrieNode node = root;
    for (final char c : word.toCharArray()) {
      final int i = c - '0';
      if (node.children[i] == null)
        node.children[i] = new TrieNode();
      node = node.children[i];
    }
  }

  public int search(final String word) {
    int prefixLength = 0;
    TrieNode node = root;
    for (final char c : word.toCharArray()) {
      final int i = c - '0';
      if (node.children[i] == null)
        break;
      node = node.children[i];
      ++prefixLength;
    }
    return prefixLength;
  }

  private TrieNode root = new TrieNode();
}

class Solution {
  public int longestCommonPrefix(int[] arr1, int[] arr2) {
    int ans = 0;
    Trie trie = new Trie();

    for (final int num : arr1)
      trie.insert(Integer.toString(num));

    for (final int num : arr2)
      ans = Math.max(ans, trie.search(Integer.toString(num)));

    return ans;
  }
}
