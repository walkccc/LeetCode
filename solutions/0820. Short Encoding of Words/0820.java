class TrieNode {
  public TrieNode[] children = new TrieNode[26];
  public int depth = 0;
}

class Solution {
  public int minimumLengthEncoding(String[] words) {
    int ans = 0;
    TrieNode root = new TrieNode();
    List<TrieNode> heads = new ArrayList<>();

    for (final String word : new HashSet<>(Arrays.asList(words)))
      heads.add(insert(root, word));

    for (TrieNode head : heads)
      if (Arrays.stream(head.children).allMatch(child -> child == null))
        ans += head.depth + 1;

    return ans;
  }

  private TrieNode insert(TrieNode root, final String word) {
    TrieNode node = root;
    for (final char c : new StringBuilder(word).reverse().toString().toCharArray()) {
      if (node.children[c - 'a'] == null)
        node.children[c - 'a'] = new TrieNode();
      node = node.children[c - 'a'];
    }
    node.depth = word.length();
    return node;
  }
}
