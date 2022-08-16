struct IndexedWord {
  string word;
  int index;
  IndexedWord(const string& word, int index) : word(word), index(index) {}
};

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
  vector<string> wordsAbbreviation(vector<string>& words) {
    const int n = words.size();
    vector<string> ans(n);
    unordered_map<string, vector<IndexedWord>> abbrevToIndexedWords;

    for (int i = 0; i < n; ++i) {
      const string abbrev = getAbbrev(words[i], 0);
      abbrevToIndexedWords[abbrev].emplace_back(words[i], i);
    }

    for (auto& [_, indexedWords] : abbrevToIndexedWords) {
      TrieNode root;
      for (const auto& iw : indexedWords)
        insertWord(&root, iw.word);
      for (const auto& iw : indexedWords) {
        const int index = firstUniqueIndex(&root, iw.word);
        ans[iw.index] = getAbbrev(iw.word, index);
      }
    }

    return ans;
  }

 private:
  string getAbbrev(const string& s, int prefixIndex) {
    const int n = s.length();
    const int num = n - (prefixIndex + 1) - 1;
    const int numLength = num < 10 ? 1 : num < 100 ? 2 : 3;
    const int abbrevLength = (prefixIndex + 1) + numLength + 1;
    if (abbrevLength >= n)
      return s;
    return s.substr(0, prefixIndex + 1) + to_string(num) + s.back();
  }

  void insertWord(TrieNode* root, const string& word) {
    TrieNode* node = root;
    for (const char c : word) {
      if (!node->children[c - 'a'])
        node->children[c - 'a'] = new TrieNode;
      node = node->children[c - 'a'];
      ++node->count;
    }
  }

  int firstUniqueIndex(TrieNode* root, const string& word) {
    TrieNode* node = root;
    for (int i = 0; i < word.length(); ++i) {
      node = node->children[word[i] - 'a'];
      if (node->count == 1)
        return i;
    }
    return word.length();
  }
};
