class TrieNode {
  public TrieNode[] children = new TrieNode[26];
  public int sum = 0;
}

class MapSum {
  public void insert(String key, int val) {
    final int diff = val - keyToVal.getOrDefault(key, 0);
    TrieNode node = root;
    for (final char c : key.toCharArray()) {
      final int i = c - 'a';
      if (node.children[i] == null)
        node.children[i] = new TrieNode();
      node = node.children[i];
      node.sum += diff;
    }
    keyToVal.put(key, val);
  }

  public int sum(String prefix) {
    TrieNode node = root;
    for (final char c : prefix.toCharArray()) {
      final int i = c - 'a';
      if (node.children[i] == null)
        return 0;
      node = node.children[i];
    }
    return node.sum;
  }

  private TrieNode root = new TrieNode();
  private Map<String, Integer> keyToVal = new HashMap<>();
}
