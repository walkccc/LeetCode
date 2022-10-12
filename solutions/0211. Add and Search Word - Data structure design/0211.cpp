struct TrieNode {
  vector<shared_ptr<TrieNode>> children;
  bool isWord = false;
  TrieNode() : children(26) {}
};

class WordDictionary {
 public:
  void addWord(const string& word) {
    shared_ptr<TrieNode> node = root;
    for (const char c : word) {
      const int i = c - 'a';
      if (!node->children[i])
        node->children[i] = make_shared<TrieNode>();
      node = node->children[i];
    }
    node->isWord = true;
  }

  bool search(const string& word) {
    return dfs(word, 0, root);
  }

 private:
  shared_ptr<TrieNode> root = make_shared<TrieNode>();

  bool dfs(const string& word, int s, shared_ptr<TrieNode> node) {
    if (s == word.length())
      return node->isWord;
    if (word[s] != '.') {
      shared_ptr<TrieNode> next = node->children[word[s] - 'a'];
      return next ? dfs(word, s + 1, next) : false;
    }

    // word[s] == '.' -> search all 26 children
    for (int i = 0; i < 26; ++i)
      if (node->children[i] && dfs(word, s + 1, node->children[i]))
        return true;

    return false;
  }
};
