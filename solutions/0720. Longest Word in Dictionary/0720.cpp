struct TrieNode {
  vector<TrieNode*> children;
  const string* word = nullptr;
  TrieNode() : children(26) {}
  ~TrieNode() {
    for (TrieNode* child : children)
      delete child;
  }
};

class Solution {
 public:
  string longestWord(vector<string>& words) {
    for (const string& word : words)
      insert(word);
    return longestWordFrom(&root);
  }

 private:
  TrieNode root;

  void insert(const string& word) {
    TrieNode* node = &root;
    for (const char c : word) {
      const int i = c - 'a';
      if (!node->children[i])
        node->children[i] = new TrieNode;
      node = node->children[i];
    }
    node->word = &word;
  }

  string longestWordFrom(TrieNode* node) {
    string ans = node->word ? *node->word : "";

    for (TrieNode* child : node->children)
      if (child && child->word) {
        string childWord = longestWordFrom(child);
        if (childWord.length() > ans.length())
          ans = childWord;
      }

    return ans;
  }
};
