struct TrieNode {
  vector<shared_ptr<TrieNode>> children;
  TrieNode() : children(10) {}
};

class Trie {
 public:
  void insert(const string& word) {
    shared_ptr<TrieNode> node = root;
    for (const char c : word) {
      const int i = c - '0';
      if (node->children[i] == nullptr)
        node->children[i] = make_shared<TrieNode>();
      node = node->children[i];
    }
  }

  int search(const string& word) {
    int prefixLength = 0;
    shared_ptr<TrieNode> node = root;
    for (const char c : word) {
      const int i = c - '0';
      if (node->children[i] == nullptr)
        break;
      node = node->children[i];
      ++prefixLength;
    }
    return prefixLength;
  }

 private:
  shared_ptr<TrieNode> root = make_shared<TrieNode>();
};

class Solution {
 public:
  int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
    int ans = 0;
    Trie trie;

    for (const int num : arr1)
      trie.insert(to_string(num));

    for (const int num : arr2)
      ans = max(ans, trie.search(to_string(num)));

    return ans;
  }
};
