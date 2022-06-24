struct TrieNode {
  vector<TrieNode*> children;
  bool isWord = false;
  TrieNode() : children(26) {}
  ~TrieNode() {
    for (TrieNode* child : children)
      delete child;
  }
};

class MagicDictionary {
 public:
  void buildDict(vector<string> dictionary) {
    for (const string& word : dictionary)
      insert(word);
  }

  bool search(string searchWord) {
    TrieNode* node = &root;
    for (int i = 0; i < searchWord.length(); ++i) {
      const int index = searchWord[i] - 'a';
      for (int j = 0; j < 26; ++j) {
        if (j == index)
          continue;
        TrieNode* child = node->children[j];
        if (!child)
          continue;
        // replace searchWord[i] with ('a' + j),
        // then check if searchWord[i + 1:] match `child`
        if (find(child, searchWord, i + 1))
          return true;
      }
      if (!node->children[index])
        return false;
      node = node->children[index];
    }
    return false;
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
    node->isWord = true;
  }

  bool find(TrieNode* node, const string& word, int s) {
    for (int i = s; i < word.length(); ++i) {
      const int index = word[i] - 'a';
      if (!node->children[index])
        return false;
      node = node->children[index];
    }
    return node->isWord;
  }
};
