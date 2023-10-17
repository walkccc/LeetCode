class TrieNode {
  public TrieNode[] children = new TrieNode[26];
  public boolean isWord = false;
}

class Solution {
  public int[][] indexPairs(String text, String[] words) {
    List<int[]> ans = new ArrayList<>();
    TrieNode root = new TrieNode();

    for (final String word : words) {
      TrieNode node = root;
      for (final char c : word.toCharArray()) {
        final int i = c - 'a';
        if (node.children[i] == null)
          node.children[i] = new TrieNode();
        node = node.children[i];
      }
      node.isWord = true;
    }

    for (int i = 0; i < text.length(); ++i) {
      TrieNode node = root;
      for (int j = i; j < text.length(); ++j) {
        final int index = text.charAt(j) - 'a';
        if (node.children[index] == null)
          break;
        node = node.children[index];
        if (node.isWord)
          ans.add(new int[] {i, j});
      }
    }

    return ans.toArray(int[][] ::new);
  }
}
