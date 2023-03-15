class TrieNode {
  public TrieNode[] children = new TrieNode[26];
  public boolean isWord = false;
}

class Encrypter {
  public Encrypter(char[] keys, String[] values, String[] dictionary) {
    for (int i = 0; i < keys.length; ++i) {
      final char key = keys[i];
      final String value = values[i];
      keyToValue.put(key, value);
      valueToKeys.putIfAbsent(value, new ArrayList<>());
      valueToKeys.get(value).add(key);
    }
    for (final String word : dictionary)
      insert(word);
  }

  public String encrypt(String word1) {
    StringBuilder sb = new StringBuilder();
    for (final char c : word1.toCharArray())
      sb.append(keyToValue.get(c));
    return sb.toString();
  }

  public int decrypt(String word2) {
    return find(word2, 0, root);
  }

  private Map<Character, String> keyToValue = new HashMap<>();
  private Map<String, List<Character>> valueToKeys = new HashMap<>();
  private TrieNode root = new TrieNode();

  void insert(final String word) {
    TrieNode node = root;
    for (final char c : word.toCharArray()) {
      final int i = c - 'a';
      if (node.children[i] == null)
        node.children[i] = new TrieNode();
      node = node.children[i];
    }
    node.isWord = true;
  }

  int find(final String word, int i, TrieNode node) {
    final String value = word.substring(i, i + 2);
    if (!valueToKeys.containsKey(value))
      return 0;

    int ans = 0;
    if (i + 2 == word.length()) {
      for (final char key : valueToKeys.get(value)) {
        TrieNode child = node.children[key - 'a'];
        if (child != null && child.isWord)
          ++ans;
      }
      return ans;
    }

    for (final char key : valueToKeys.get(value)) {
      if (node.children[key - 'a'] == null)
        continue;
      ans += find(word, i + 2, node.children[key - 'a']);
    }

    return ans;
  }
}
