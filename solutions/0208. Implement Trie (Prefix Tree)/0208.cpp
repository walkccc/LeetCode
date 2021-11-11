struct TrieNode {
  vector<TrieNode*> children;
  bool isWord = false;
  TrieNode() : children(26) {}
  ~TrieNode() {
    for (TrieNode* child : children)
      delete child;
  }
};

class Trie {
 public:
  void insert(const string& word) {
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
      const int i = c - 'a';
      if (!node->children[i])
        return nullptr;
      node = node->children[i];
    }
    return node;
  }
};
