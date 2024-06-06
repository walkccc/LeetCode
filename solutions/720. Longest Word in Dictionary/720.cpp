struct TrieNode {
  vector<shared_ptr<TrieNode>> children;
  const string* word = nullptr;
  TrieNode() : children(26) {}
};

class Solution {
 public:
  string longestWord(vector<string>& words) {
    for (const string& word : words)
      insert(word);
    return longestWordFrom(root);
  }

 private:
  shared_ptr<TrieNode> root = make_shared<TrieNode>();

  void insert(const string& word) {
    shared_ptr<TrieNode> node = root;
    for (const char c : word) {
      const int i = c - 'a';
      if (node->children[i] == nullptr)
        node->children[i] = make_shared<TrieNode>();
      node = node->children[i];
    }
    node->word = &word;
  }

  string longestWordFrom(shared_ptr<TrieNode> node) {
    string ans = node->word ? *node->word : "";

    for (shared_ptr<TrieNode> child : node->children)
      if (child && child->word) {
        string childWord = longestWordFrom(child);
        if (childWord.length() > ans.length())
          ans = childWord;
      }

    return ans;
  }
};
