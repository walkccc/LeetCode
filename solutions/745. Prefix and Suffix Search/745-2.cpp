struct TrieNode {
  vector<shared_ptr<TrieNode>> children;
  int weight = -1;
  TrieNode() : children(27) {}
};

class Trie {
 public:
  void insert(const string& word, int weight) {
    shared_ptr<TrieNode> node = root;
    for (const char c : word) {
      const int i = c - 'a';
      if (node->children[i] == nullptr)
        node->children[i] = make_shared<TrieNode>();
      node = node->children[i];
      node->weight = weight;
    }
  }

  int startsWith(const string& word) {
    shared_ptr<TrieNode> node = root;
    for (const char c : word) {
      const int i = c - 'a';
      if (node->children[i] == nullptr)
        return -1;
      node = node->children[i];
    }
    return node->weight;
  }

 private:
  shared_ptr<TrieNode> root = make_shared<TrieNode>();
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
