class TrieNode {
  public TrieNode[] children = new TrieNode[26];
  public int count = 0;
}

class Solution {
  public int[] sumPrefixScores(String[] words) {
    int[] ans = new int[words.length];

    for (final String word : words)
      insert(word);

    for (int i = 0; i < words.length; ++i)
      ans[i] = getScore(words[i]);

    return ans;
  }

  private TrieNode root = new TrieNode();

  private void insert(String word) {
    TrieNode node = root;
    for (final char c : word.toCharArray()) {
      final int i = c - 'a';
      if (node.children[i] == null)
        node.children[i] = new TrieNode();
      node = node.children[i];
      ++node.count;
    }
  }

  private int getScore(String word) {
    TrieNode node = root;
    int score = 0;
    for (final char c : word.toCharArray()) {
      node = node.children[c - 'a'];
      score += node.count;
    }
    return score;
  }
}
