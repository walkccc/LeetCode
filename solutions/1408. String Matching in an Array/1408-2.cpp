struct TrieNode {
  vector<shared_ptr<TrieNode>> children;
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
    return true;
  }

 private:
  shared_ptr<TrieNode> root = make_shared<TrieNode>();
};

class Solution {
 public:
  vector<string> stringMatching(vector<string>& words) {
    vector<string> ans;
    Trie trie;

    ranges::sort(words, [](const string& a, const string& b) {
      return a.length() > b.length();
    });

    for (const string& word : words) {
      if (trie.search(word))
        ans.push_back(word);
      for (int i = 0; i < word.length(); ++i)
        trie.insert(word.substr(i));
    }

    return ans;
  }
};
