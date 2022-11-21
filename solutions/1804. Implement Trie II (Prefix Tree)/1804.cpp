struct TrieNode {
  vector<shared_ptr<TrieNode>> children;
  int prefixCount = 0;
  int wordCount = 0;
  TrieNode() : children(26) {}
};

class Trie {
 public:
  void insert(string word) {
    shared_ptr<TrieNode> node = root;
    for (const char c : word) {
      const int i = c - 'a';
      if (node->children[i] == nullptr)
        node->children[i] = make_shared<TrieNode>();
      node = node->children[i];
      ++node->prefixCount;
    }
    ++node->wordCount;
  }

  int countWordsEqualTo(string word) {
    shared_ptr<TrieNode> node = find(word);
    return node ? node->wordCount : 0;
  }

  int countWordsStartingWith(string prefix) {
    shared_ptr<TrieNode> node = find(prefix);
    return node ? node->prefixCount : 0;
  }

  void erase(string word) {
    shared_ptr<TrieNode> node = root;
    for (const char c : word) {
      const int i = c - 'a';
      node = node->children[i];
      --node->prefixCount;
    }
    --node->wordCount;
  }

 private:
  shared_ptr<TrieNode> root = make_shared<TrieNode>();

  shared_ptr<TrieNode> find(const string& s) {
    shared_ptr<TrieNode> node = root;
    for (const char c : s) {
      const int i = c - 'a';
      if (node->children[i] == nullptr)
        return nullptr;
      node = node->children[i];
    }
    return node;
  }
};
