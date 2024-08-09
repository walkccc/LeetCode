struct TrieNode {
  vector<shared_ptr<TrieNode>> children;
  int sum = 0;
  TrieNode() : children(26) {}
};

class MapSum {
 public:
  void insert(string key, int val) {
    const int diff = val - keyToVal[key];
    shared_ptr<TrieNode> node = root;
    for (const char c : key) {
      const int i = c - 'a';
      if (node->children[i] == nullptr)
        node->children[i] = make_shared<TrieNode>();
      node = node->children[i];
      node->sum += diff;
    }
    keyToVal[key] = val;
  }

  int sum(string prefix) {
    shared_ptr<TrieNode> node = root;
    for (const char c : prefix) {
      const int i = c - 'a';
      if (node->children[i] == nullptr)
        return 0;
      node = node->children[i];
    }
    return node->sum;
  }

 private:
  shared_ptr<TrieNode> root = make_shared<TrieNode>();
  unordered_map<string, int> keyToVal;
};
