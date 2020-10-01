struct TrieNode {
  TrieNode() : children(26), isWord(false) {}
  ~TrieNode() {
    for (TrieNode* child : children)
      delete child;
  }
  vector<TrieNode*> children;
  bool isWord;
};

class Trie {
 public:
  void insert(const string& word) {
    TrieNode* node = &root;
    for (const char c : word) {
      if (!node->children[c - 'a'])
        node->children[c - 'a'] = new TrieNode;
      node = node->children[c - 'a'];
    }
    node->isWord = true;
  }

  bool search(const string& word) {
    TrieNode* node = find(word);
    return node && node->isWord;
  }

  bool startsWith(const string& prefix) {
    return find(prefix);
  }

 private:
  TrieNode root;

  TrieNode* find(const string& prefix) {
    TrieNode* node = &root;
    for (const char c : prefix) {
      if (!node->children[c - 'a'])
        return nullptr;
      node = node->children[c - 'a'];
    }
    return node;
  }
};