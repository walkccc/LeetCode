class TrieNode {
  public TrieNode[] children = new TrieNode[26];
  public int cost = Integer.MAX_VALUE;
}

class Trie {
  // Inserts a word with a cost.
  public void insert(String word, int cost) {
    TrieNode node = root;
    for (final char c : word.toCharArray()) {
      final int i = c - 'a';
      if (node.children[i] == null)
        node.children[i] = new TrieNode();
      node = node.children[i];
    }
    node.cost = Math.min(node.cost, cost);
  }

  // Returns the minimum cost to construct s[i:].
  public int search(final String word, int i, Integer[] mem) {
    if (i == word.length())
      return 0;
    if (mem[i] != null)
      return mem[i];
    int cost = Integer.MAX_VALUE;
    TrieNode node = root;
    for (int j = i; j < word.length(); ++j) {
      final int index = word.charAt(j) - 'a';
      if (node.children[index] == null)
        break;
      node = node.children[index];
      if (node.cost != Integer.MAX_VALUE) {
        final int childCost = search(word, j + 1, mem);
        if (childCost != Integer.MAX_VALUE)
          cost = Math.min(cost, node.cost + childCost);
      }
    }
    return mem[i] = cost;
  }

  private TrieNode root = new TrieNode();
}

class Solution {
  public int minimumCost(String target, String[] words, int[] costs) {
    Trie trie = new Trie();

    for (int i = 0; i < words.length; ++i)
      trie.insert(words[i], costs[i]);

    final int ans = trie.search(target, 0, new Integer[target.length()]);
    return ans == Integer.MAX_VALUE ? -1 : ans;
  }
}
