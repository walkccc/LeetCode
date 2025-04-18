struct TrieNode {
  vector<shared_ptr<TrieNode>> children;
  int count = 0;
  TrieNode() : children(26) {}
};

class Trie {
 public:
  void insert(const string& word) {
    shared_ptr<TrieNode> node = root;
    for (const char c : word) {
      const int i = c - 'a';
      if (node->children[i] == nullptr)
        node->children[i] = make_shared<TrieNode>();
      node = node->children[i];
      ++node->count;
    }
  }

  bool search(const string& word) {
    shared_ptr<TrieNode> node = root;
    for (const char c : word) {
      const int i = c - 'a';
      if (node->children[i] == nullptr)
        return false;
      node = node->children[i];
    }
    return node->count > 1;
  }

 private:
  shared_ptr<TrieNode> root = make_shared<TrieNode>();
};

class Solution {
 public:
  vector<string> stringMatching(vector<string>& words) {
    vector<string> ans;
    Trie trie;

    for (const string& word : words)
      for (int i = 0; i < word.length(); ++i)
        trie.insert(word.substr(i));

    for (const string& word : words)
      if (trie.search(word))
        ans.push_back(word);

    return ans;
  }
};
