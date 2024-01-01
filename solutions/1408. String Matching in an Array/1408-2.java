class TrieNode {
  public TrieNode[] children = new TrieNode[26];
}

class Trie {
  public void insert(String word) {
    TrieNode node = root;
    for (final char c : word.toCharArray()) {
      final int i = c - 'a';
      if (node.children[i] == null)
        node.children[i] = new TrieNode();
      node = node.children[i];
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
    return true;
  }

  private TrieNode root = new TrieNode();
}

class Solution {
  public List<String> stringMatching(String[] words) {
    List<String> ans = new ArrayList<>();
    Trie trie = new Trie();

    Arrays.sort(words, (a, b) -> b.length() - a.length());

    for (final String word : words) {
      if (trie.search(word))
        ans.add(word);
      for (int i = 0; i < word.length(); ++i)
        trie.insert(word.substring(i));
    }

    return ans;
  }
}
