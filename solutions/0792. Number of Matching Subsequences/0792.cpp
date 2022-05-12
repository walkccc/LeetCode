struct TrieNode {
  vector<TrieNode*> children;
  int count = 0;
  TrieNode() : children(26) {}
  ~TrieNode() {
    for (TrieNode* child : children)
      delete child;
  }
};

class Solution {
 public:
  int numMatchingSubseq(string S, vector<string>& words) {
    for (const string& word : words)
      insert(word);

    return dfs(S, 0, &root);
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
    ++node->count;
  }

  int dfs(const string& s, int i, TrieNode* node) {
    int ans = node->count;
    if (i >= s.length())
      return ans;

    for (int j = 0; j < 26; ++j)
      if (node->children[j]) {
        const int index = s.find('a' + j, i);
        if (index != -1)
          ans += dfs(s, index + 1, node->children[j]);
      }

    return ans;
  }
};
