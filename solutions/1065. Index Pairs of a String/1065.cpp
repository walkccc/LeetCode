struct TrieNode {
  vector<shared_ptr<TrieNode>> children;
  bool isWord = false;
  TrieNode() : children(26) {}
};

class Solution {
 public:
  vector<vector<int>> indexPairs(string text, vector<string>& words) {
    vector<vector<int>> ans;
    shared_ptr<TrieNode> root = make_shared<TrieNode>();

    for (const string& word : words) {
      shared_ptr<TrieNode> node = root;
      for (const char c : word) {
        const int i = c - 'a';
        if (node->children[i] == nullptr)
          node->children[i] = make_shared<TrieNode>();
        node = node->children[i];
      }
      node->isWord = true;
    }

    for (int i = 0; i < text.length(); ++i) {
      shared_ptr<TrieNode> node = root;
      for (int j = i; j < text.length(); j++) {
        const int index = text[j] - 'a';
        if (node->children[index] == nullptr)
          break;
        node = node->children[index];
        if (node->isWord)
          ans.push_back({i, j});
      }
    }

    return ans;
  }
};
