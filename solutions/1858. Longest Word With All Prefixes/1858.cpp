struct TrieNode {
  vector<TrieNode*> children;
  bool isWord = false;
  TrieNode() : children(26) {}
  ~TrieNode() {
    for (TrieNode* child : children)
      delete child;
  }
};

class Solution {
 public:
  string longestWord(vector<string>& words) {
    string ans;

    for (const string& word : words)
      insert(word);

    for (const string& word : words) {
      if (!allPrefixed(word))
        continue;
      if (ans.length() < word.length() ||
          (ans.length() == word.length() && ans > word))
        ans = word;
    }

    return ans;
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
    node->isWord = true;
  }

  bool allPrefixed(const string& word) {
    TrieNode* node = &root;
    for (const char c : word) {
      const int i = c - 'a';
      node = node->children[i];
      if (!node->isWord)
        return false;
    }
    return true;
  }
};
