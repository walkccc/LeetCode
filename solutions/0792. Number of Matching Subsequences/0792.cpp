struct TrieNode {
  TrieNode() : children(26), count(0) {}
  ~TrieNode() {
    for (TrieNode* child : children)
      delete child;
  }
  vector<TrieNode*> children;
  int count;
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

  int dfs(const string& S, int s, TrieNode* node) {
    int ans = node->count;

    if (s >= S.length())
      return ans;

    for (int i = 0; i < 26; ++i)
      if (node->children[i]) {
        const int index = S.find('a' + i, s);
        if (index != -1)
          ans += dfs(S, index + 1, node->children[i]);
      }

    return ans;
  }
};
