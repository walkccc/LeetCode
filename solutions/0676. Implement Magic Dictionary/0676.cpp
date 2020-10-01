struct TrieNode {
  TrieNode() : children(26), isWord(false) {}
  ~TrieNode() {
    for (TrieNode* child : children)
      delete child;
  }
  vector<TrieNode*> children;
  bool isWord;
};

class MagicDictionary {
 public:
  void buildDict(vector<string> dict) {
    for (const string& word : dict)
      insert(word);
  }

  bool search(string word) {
    TrieNode* node = &root;
    for (int i = 0; i < word.length(); ++i) {
      const char c = word[i];
      for (int j = 0; j < 26; ++j) {
        if ('a' + j == c) continue;        // current branch exists
        if (!node->children[j]) continue;  // no branch j
        if (find(word, i + 1, node->children[j]))
          return true;
      }
      if (!node->children[c - 'a']) return false;
      node = node->children[c - 'a'];
    }
    return false;
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
    node->isWord = true;
  }

  bool find(const string& word, int s, TrieNode* node) {
    for (int i = s; i < word.length(); ++i) {
      const char c = word[i];
      if (!node->children[c - 'a'])
        return false;
      node = node->children[c - 'a'];
    }
    return node->isWord;
  }
};