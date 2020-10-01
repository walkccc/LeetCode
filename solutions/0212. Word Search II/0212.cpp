struct TrieNode {
  TrieNode() : children(26), word(nullptr) {}
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
    const int m = board.size();
    const int n = board[0].size();

    vector<string> ans;

    for (const string& word : words)
      insert(word);

    function<void(int, int, TrieNode*)> dfs = [&](int i, int j,
                                                  TrieNode* node) {
      if (i < 0 || i == m || j < 0 || j == n) return;
      if (board[i][j] == '*') return;

      const char c = board[i][j];
      TrieNode* next = node->children[c - 'a'];
      if (!next) return;
      if (next->word) {
        ans.push_back(*next->word);
        next->word = nullptr;
      }

      board[i][j] = '*';
      dfs(i + 1, j, next);
      dfs(i - 1, j, next);
      dfs(i, j + 1, next);
      dfs(i, j - 1, next);
      board[i][j] = c;
    };

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        dfs(i, j, &root);

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
};