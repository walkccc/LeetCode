struct TrieNode {
  vector<shared_ptr<TrieNode>> children;
  const string* word = nullptr;
  TrieNode() : children(26) {}
};

class Solution {
 public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    vector<string> ans;

    for (const string& word : words)
      insert(word);

    for (int i = 0; i < board.size(); ++i)
      for (int j = 0; j < board[0].size(); ++j)
        dfs(board, i, j, root, ans);

    return ans;
  }

 private:
  shared_ptr<TrieNode> root = make_shared<TrieNode>();

  void insert(const string& word) {
    shared_ptr<TrieNode> node = root;
    for (const char c : word) {
      const int i = c - 'a';
      if (!node->children[i])
        node->children[i] = make_shared<TrieNode>();
      node = node->children[i];
    }
    node->word = &word;
  }

  void dfs(vector<vector<char>>& board, int i, int j, shared_ptr<TrieNode> node,
           vector<string>& ans) {
    if (i < 0 || i == board.size() || j < 0 || j == board[0].size())
      return;
    if (board[i][j] == '*')
      return;

    const char c = board[i][j];
    auto child = node->children[c - 'a'];
    if (!child)
      return;
    if (child->word) {
      ans.push_back(*child->word);
      child->word = nullptr;
    }

    board[i][j] = '*';
    dfs(board, i + 1, j, child, ans);
    dfs(board, i - 1, j, child, ans);
    dfs(board, i, j + 1, child, ans);
    dfs(board, i, j - 1, child, ans);
    board[i][j] = c;
  }
};
