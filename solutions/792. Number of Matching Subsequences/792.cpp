struct TrieNode {
  vector<shared_ptr<TrieNode>> children;
  int count = 0;
  TrieNode() : children(26) {}
};

class Solution {
 public:
  int numMatchingSubseq(string s, vector<string>& words) {
    for (const string& word : words)
      insert(word);
    return dfs(s, 0, root);
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
    ++node->count;
  }

  int dfs(const string& s, int i, shared_ptr<TrieNode> node) {
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
