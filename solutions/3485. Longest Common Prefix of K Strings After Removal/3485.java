class TrieNode {
  public TrieNode[] children = new TrieNode[26];
  public int count = 0;
}

class Trie {
  public Trie(int k) {
    this.k = k;
  }

  public void insert(final String word) {
    TrieNode node = root;
    for (int i = 0; i < word.length(); ++i) {
      final int sz = i + 1;
      final int index = word.charAt(i) - 'a';
      if (node.children[index] == null)
        node.children[index] = new TrieNode();
      node = node.children[index];
      ++node.count;
      if (node.count >= k && prefixLengthsCount.merge(sz, 1, Integer::sum) == 1)
        prefixLengths.add(sz);
    }
  }

  public void erase(final String word) {
    TrieNode node = root;
    for (int i = 0; i < word.length(); ++i) {
      final int sz = i + 1;
      final int index = word.charAt(i) - 'a';
      if (node.children[index] == null)
        node.children[index] = new TrieNode();
      node = node.children[index];
      if (node.count == k && prefixLengthsCount.merge(sz, -1, Integer::sum) == 0)
        prefixLengths.remove(sz);
      --node.count;
    }
  }

  public int getLongestCommonPrefix() {
    return prefixLengths.isEmpty() ? 0 : prefixLengths.first();
  }

  private final int k;
  private TrieNode root = new TrieNode();
  private Map<Integer, Integer> prefixLengthsCount = new HashMap<>();
  private TreeSet<Integer> prefixLengths = new TreeSet<>(Collections.reverseOrder());
}

class Solution {
  public int[] longestCommonPrefix(String[] words, int k) {
    final int[] ans = new int[words.length];
    Trie trie = new Trie(k);

    for (final String word : words)
      trie.insert(word);

    for (int i = 0; i < words.length; ++i) {
      trie.erase(words[i]);
      ans[i] = trie.getLongestCommonPrefix();
      trie.insert(words[i]);
    }

    return ans;
  }
}
