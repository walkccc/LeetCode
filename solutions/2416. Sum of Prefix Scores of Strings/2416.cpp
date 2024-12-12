struct TrieNode {
  vector<shared_ptr<TrieNode>> children;
  int count = 0;
  TrieNode() : children(26) {}
};

class Solution {
 public:
  vector<int> sumPrefixScores(vector<string>& words) {
    vector<int> ans;

    for (const string& word : words)
      insert(word);

    for (const string& word : words)
      ans.push_back(getScore(word));

    return ans;
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
      ++node->count;
    }
  }

  int getScore(const string& word) {
    shared_ptr<TrieNode> node = root;
    int score = 0;
    for (const char c : word) {
      node = node->children[c - 'a'];
      score += node->count;
    }
    return score;
  }
};
