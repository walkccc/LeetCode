struct TrieNode {
  TrieNode() : children(26), word(nullptr) {
  }
  ~TrieNode() {
    for (TrieNode* child : children)
      delete child;
  }
  vector<TrieNode*> children;
  const string* word;
};

class Solution {
 public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    vector<string> ans;

    for (const string& word : words)
      insert(word);

    for (int i = 0; i < board.size(); ++i)
      for (int j = 0; j < board[0].size(); ++j)
        dfs(board, i, j, &root, ans);

    return ans;
  }

 private:
  TrieNode root;

  void insert(const string& word) {
    TrieNode* node = &root;
    for (const char c : word) {
      if (!node->children[c - 'a'])
        node->children[c - 'a'] = new TrieNode;
      node = node->children[c - 'a'];
    }
    node->word = &word;
  }

  void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node,
           vector<string>& ans) {
    if (i < 0 || i == board.size() || j < 0 || j == board[0].size())
      return;
    if (board[i][j] == '*')
      return;

    const char c = board[i][j];
    TrieNode* next = node->children[c - 'a'];
    if (!next)
      return;
    if (next->word) {
      ans.push_back(*next->word);
      next->word = nullptr;
    }

    board[i][j] = '*';
    dfs(board, i + 1, j, next, ans);
    dfs(board, i - 1, j, next, ans);
    dfs(board, i, j + 1, next, ans);
    dfs(board, i, j - 1, next, ans);
    board[i][j] = c;
  }
};
