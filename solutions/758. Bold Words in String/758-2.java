class TrieNode {
  public TrieNode[] children = new TrieNode[26];
  public boolean isWord = false;
}

class Solution {
  public String boldWords(String[] words, String s) {
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
      final int i = c - 'a';
      if (node.children[i] == null)
        node.children[i] = new TrieNode();
      node = node.children[i];
    }
    node.isWord = true;
  }

  private int find(final String s, int i) {
    TrieNode node = root;
    int ans = -1;
    for (int j = i; j < s.length(); ++j) {
      final int index = s.charAt(j) - 'a';
      if (node.children[index] == null)
        return ans;
      node = node.children[index];
      if (node.isWord)
        ans = j;
    }
    return ans;
  }
}
