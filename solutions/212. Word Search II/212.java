class TrieNode {
  public TrieNode[] children = new TrieNode[26];
  public String word;
}

class Solution {
  public List<String> findWords(char[][] board, String[] words) {
    for (final String word : words)
      insert(word);

    List<String> ans = new ArrayList<>();

    for (int i = 0; i < board.length; ++i)
      for (int j = 0; j < board[0].length; ++j)
        dfs(board, i, j, root, ans);

    return ans;
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
    node.word = word;
  }

  private void dfs(char[][] board, int i, int j, TrieNode node, List<String> ans) {
    if (i < 0 || i == board.length || j < 0 || j == board[0].length)
      return;
    if (board[i][j] == '*')
      return;

    final char c = board[i][j];
    TrieNode child = node.children[c - 'a'];
    if (child == null)
      return;
    if (child.word != null) {
      ans.add(child.word);
      child.word = null;
    }

    board[i][j] = '*';
    dfs(board, i + 1, j, child, ans);
    dfs(board, i - 1, j, child, ans);
    dfs(board, i, j + 1, child, ans);
    dfs(board, i, j - 1, child, ans);
    board[i][j] = c;
  }
}
