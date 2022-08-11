struct TrieNode {
  vector<TrieNode*> children;
  int depth = 0;
  TrieNode() : children(26) {}
  ~TrieNode() {
    for (TrieNode* child : children)
      delete child;
  }
};

class Solution {
 public:
  int minimumLengthEncoding(vector<string>& words) {
    int ans = 0;
    TrieNode root;
    vector<TrieNode*> heads;

    for (const auto& word : unordered_set<string>(begin(words), end(words)))
      heads.push_back(insert(&root, word));

    for (TrieNode* head : heads)
      if (all_of(begin(head->children), end(head->children),
                 [](const auto& child) { return child == nullptr; }))
        ans += head->depth + 1;

    return ans;
  }

 private:
  TrieNode* insert(TrieNode* root, const string& word) {
    TrieNode* node = root;
    for (const char c : string(rbegin(word), rend(word))) {
      if (!node->children[c - 'a'])
        node->children[c - 'a'] = new TrieNode;
      node = node->children[c - 'a'];
    }
    node->depth = word.length();
    return node;
  }
};
