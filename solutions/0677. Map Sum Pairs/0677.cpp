struct TrieNode {
  vector<TrieNode*> children;
  int sum = 0;
  TrieNode() : children(26) {}
  ~TrieNode() {
    for (TrieNode* child : children)
      delete child;
  }
};

class MapSum {
 public:
  void insert(string key, int val) {
    const int diff = val - keyToVal[key];
    TrieNode* node = &root;
    for (const char c : key) {
      if (!node->children[c - 'a'])
        node->children[c - 'a'] = new TrieNode;
      node = node->children[c - 'a'];
      node->sum += diff;
    }
    keyToVal[key] = val;
  }

  int sum(string prefix) {
    TrieNode* node = &root;
    for (const char c : prefix) {
      if (!node->children[c - 'a'])
        return 0;
      node = node->children[c - 'a'];
    }
    return node->sum;
  }

 private:
  TrieNode root;
  unordered_map<string, int> keyToVal;
};
