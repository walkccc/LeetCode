struct TrieNode {
 public:
  unordered_map<char, shared_ptr<TrieNode>> children;
  bool isWord = false;
};

class Trie {
 public:
  void insert(const string& word) {
    shared_ptr<TrieNode> node = root;
    for (const char c : word) {
      if (node->children[c] == nullptr)
        node->children[c] = make_shared<TrieNode>();
      node = node->children[c];
    }
    node->isWord = true;
  }

  bool search(const string& word, int l, int r) {
    shared_ptr<TrieNode> node = root;
    for (int j = l; j <= r; ++j) {
      const char c = word[j];
      if (node->children[c] == nullptr)
        return false;
      node = node->children[c];
    }
    return node->isWord;
  }

 private:
  shared_ptr<TrieNode> root = make_shared<TrieNode>();
};

class Solution {
 public:
  int longestValidSubstring(string word, vector<string>& forbidden) {
    int ans = 0;
    Trie trie;

    for (const string& s : forbidden)
      trie.insert(s);

    // r is the rightmost index to make word[l..r] a valid substring.
    int r = word.length() - 1;
    for (int l = word.length() - 1; l >= 0; --l) {
      for (int end = l; end < min(l + 10, r + 1); ++end)
        if (trie.search(word, l, end)) {
          r = end - 1;
          break;
        }
      ans = max(ans, r - l + 1);
    }

    return ans;
  }
};
