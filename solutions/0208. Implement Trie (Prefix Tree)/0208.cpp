struct TrieNode {
  vector<shared_ptr<TrieNode>> children;
  bool isWord = false;
  TrieNode() : children(26) {}
};

class Trie {
 public:
  void insert(const string& word) {
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
    shared_ptr<TrieNode> node = find(word);
    return node && node->isWord;
  }

  bool startsWith(const string& prefix) {
    return find(prefix) != nullptr;
  }

 private:
  shared_ptr<TrieNode> root = make_shared<TrieNode>();

  shared_ptr<TrieNode> find(const string& prefix) {
    shared_ptr<TrieNode> node = root;
    for (const char c : prefix) {
      const int i = c - 'a';
      if (!node->children[i])
        return nullptr;
      node = node->children[i];
    }
    return node;
  }
};
