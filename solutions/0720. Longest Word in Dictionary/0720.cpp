struct TrieNode {
  TrieNode() : children(26), word(nullptr) {}
  ~TrieNode() {
    for (TrieNode* child : children)
      delete child;
  }
  vector<TrieNode*> children;
  const string* word;
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
      if (!node->children[c - 'a'])
        node->children[c - 'a'] = new TrieNode;
      node = node->children[c - 'a'];
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