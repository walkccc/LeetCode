struct TrieNode {
  TrieNode() : children(26), isWord(false) {}
  ~TrieNode() {
    for (TrieNode* child : children)
      delete child;
  }
  vector<TrieNode*> children;
  bool isWord;
};

class WordDictionary {
 public:
  void addWord(const string& word) {
    TrieNode* node = &root;
    for (const char c : word) {
      const int i = c - 'a';
      if (!node->children[i])
        node->children[i] = new TrieNode;
      node = node->children[i];
    }
    node->isWord = true;
  }

  bool search(const string& word) {
    return dfs(word, 0, &root);
  }

 private:
  TrieNode root;

  bool dfs(const string& word, int s, TrieNode* node) {
    if (s == word.length())
      return node->isWord;
    if (word[s] != '.') {
      TrieNode* next = node->children[word[s] - 'a'];
      return next ? dfs(word, s + 1, next) : false;
    }

    // word[s] == '.' -> search all 26 children
    for (int i = 0; i < 26; ++i)
      if (node->children[i] && dfs(word, s + 1, node->children[i]))
        return true;

    return false;
  }
};
