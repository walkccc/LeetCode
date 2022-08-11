struct TrieNode {
  vector<TrieNode*> children;
  int weight = -1;
  TrieNode() : children(27) {}
  ~TrieNode() {
    for (TrieNode* child : children)
      delete child;
  }
};

class Trie {
 public:
  void insert(const string& word, int weight) {
    TrieNode* node = &root;
    for (const char c : word) {
      if (!node->children[c - 'a'])
        node->children[c - 'a'] = new TrieNode;
      node = node->children[c - 'a'];
      node->weight = weight;
    }
  }

  int startsWith(const string& word) {
    TrieNode* node = &root;
    for (const char c : word) {
      if (!node->children[c - 'a'])
        return -1;
      node = node->children[c - 'a'];
    }
    return node->weight;
  }

 private:
  TrieNode root;
};

class WordFilter {
 public:
  WordFilter(vector<string>& words) {
    for (int i = 0; i < words.size(); ++i)
      for (int j = 0; j <= words[i].length(); ++j)
        trie.insert(words[i].substr(j) + '{' + words[i], i);
  }

  int f(string prefix, string suffix) {
    return trie.startsWith(suffix + '{' + prefix);
  }

 private:
  Trie trie;
};
