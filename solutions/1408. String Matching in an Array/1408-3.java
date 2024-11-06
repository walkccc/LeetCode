class TrieNode {
  public TrieNode[] children = new TrieNode[26];
  public int count = 0;
}

class Trie {
  public void insert(String word) {
    TrieNode node = root;
    for (final char c : word.toCharArray()) {
      final int i = c - 'a';
      if (node.children[i] == null)
        node.children[i] = new TrieNode();
      node = node.children[i];
      ++node.count;
    }
  }

  public boolean search(String word) {
    TrieNode node = root;
    for (final char c : word.toCharArray()) {
      final int i = c - 'a';
      if (node.children[i] == null)
        return false;
      node = node.children[i];
    }
    return node.count > 1;
  }

  private TrieNode root = new TrieNode();
}

class Solution {
  public List<String> stringMatching(String[] words) {
    List<String> ans = new ArrayList<>();
    Trie trie = new Trie();

    for (final String word : words)
      for (int i = 0; i < word.length(); ++i)
        trie.insert(word.substring(i));

    for (final String word : words)
      if (trie.search(word))
        ans.add(word);

    return ans;
  }
}
