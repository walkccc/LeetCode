class TrieNode {
  public TrieNode[] children = new TrieNode[128];
  public boolean isWord = false;
}

class Solution {
  public String addBoldTag(String s, String[] words) {
    final int n = s.length();
    StringBuilder sb = new StringBuilder();
    // bold[i] := true if s[i] should be bolded
    boolean[] bold = new boolean[n];

    for (final String word : words)
      insert(word);

    int boldEnd = -1; // `s[i..boldEnd]` should be bolded.
    for (int i = 0; i < n; ++i) {
      boldEnd = Math.max(boldEnd, find(s, i));
      bold[i] = boldEnd >= i;
    }

    // Construct the string with the bold tags.
    int i = 0;
    while (i < n)
      if (bold[i]) {
        int j = i;
        while (j < n && bold[j])
          ++j;
        // s[i..j) should be bolded
        sb.append("<b>").append(s.substring(i, j)).append("</b>");
        i = j;
      } else {
        sb.append(s.charAt(i++));
      }

    return sb.toString();
  }

  private TrieNode root = new TrieNode();

  private void insert(final String word) {
    TrieNode node = root;
    for (final char c : word.toCharArray()) {
      if (node.children[c] == null)
        node.children[c] = new TrieNode();
      node = node.children[c];
    }
    node.isWord = true;
  }

  private int find(final String s, int i) {
    TrieNode node = root;
    int ans = -1;
    for (int j = i; j < s.length(); ++j) {
      if (node.children[s.charAt(j)] == null)
        return ans;
      node = node.children[s.charAt(j)];
      if (node.isWord)
        ans = j;
    }
    return ans;
  }
}
