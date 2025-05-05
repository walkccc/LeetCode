class TrieNode {
  public TrieNode[] children = new TrieNode[10];
  public boolean isWord = false;
}

class Trie {
  public void insert(String number) {
    TrieNode node = root;
    for (final char d : number.toCharArray()) {
      final int i = d - '0';
      if (node.children[i] == null)
        node.children[i] = new TrieNode();
      node = node.children[i];
    }
    node.isWord = true;
  }

  // Returns true if the number is a prefix of any number in the trie or any
  // number in the trie is a prefix of the number
  public boolean search(String number) {
    TrieNode node = root;
    for (final char d : number.toCharArray()) {
      final int i = d - '0';
      if (node.children[i] == null)
        return false;
      node = node.children[i];
      if (node.isWord)
        return true;
    }
    return true; // The number is a prefix of some number in the trie
  }

  private TrieNode root = new TrieNode();
}

class Solution {
  public boolean phonePrefix(String[] numbers) {
    Trie trie = new Trie();

    for (final String number : numbers) {
      if (trie.search(number))
        return false;
      trie.insert(number);
    }

    return true;
  }
}
