struct TrieNode {
  vector<shared_ptr<TrieNode>> children;
  int count = 0;
  TrieNode() : children(26) {}
};

class Trie {
 public:
  Trie(int k) : k(k) {}

  void insert(const string& word) {
    shared_ptr<TrieNode> node = root;
    for (int i = 0; i < word.length(); ++i) {
      const int sz = i + 1;
      const int index = word[i] - 'a';
      if (node->children[index] == nullptr)
        node->children[index] = make_shared<TrieNode>();
      node = node->children[index];
      ++node->count;
      if (node->count >= k && prefixLengthsCount[sz]++ == 0)
        prefixLengths.insert(sz);
    }
  }

  void erase(const string& word) {
    shared_ptr<TrieNode> node = root;
    for (int i = 0; i < word.length(); ++i) {
      const int sz = i + 1;
      const int index = word[i] - 'a';
      if (node->children[index] == nullptr)
        node->children[index] = make_shared<TrieNode>();
      node = node->children[index];
      if (node->count == k && prefixLengthsCount[sz]-- == 1)
        prefixLengths.erase(sz);
      --node->count;
    }
  }

  int getLongestCommonPrefix() const {
    return prefixLengths.empty() ? 0 : *prefixLengths.begin();
  }

 private:
  const int k;
  shared_ptr<TrieNode> root = make_shared<TrieNode>();
  unordered_map<int, int> prefixLengthsCount;
  set<int, greater<>> prefixLengths;
};

class Solution {
 public:
  vector<int> longestCommonPrefix(vector<string>& words, int k) {
    vector<int> ans;
    Trie trie(k);

    for (const string& word : words)
      trie.insert(word);

    for (const string& word : words) {
      trie.erase(word);
      ans.push_back(trie.getLongestCommonPrefix());
      trie.insert(word);
    }

    return ans;
  }
};
