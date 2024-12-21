struct TrieNode {
  unordered_map<int, shared_ptr<TrieNode>> children;
  int count = 0;
};

class Trie {
 public:
  int insert(const string& word) {
    const int n = word.length();
    int count = 0;
    shared_ptr<TrieNode> node = root;
    for (int i = 0; i < n; ++i) {
      const int j = hash(word[i], word[n - 1 - i]);
      if (node->children[j] == nullptr)
        node->children[j] = make_shared<TrieNode>();
      node = node->children[j];
      count += node->count;
    }
    ++node->count;
    return count;
  }

 private:
  shared_ptr<TrieNode> root = make_shared<TrieNode>();

  static int hash(char prefix, char suffix) {
    return 26 * (prefix - 'a') + (suffix - 'a');
  }
};

class Solution {
 public:
  // Same as 3042. Count Prefix and Suffix Pairs I
  long long countPrefixSuffixPairs(vector<string>& words) {
    long ans = 0;
    Trie trie;

    for (const string& word : words)
      ans += trie.insert(word);

    return ans;
  }
};
