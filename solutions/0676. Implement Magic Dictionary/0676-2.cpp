struct TrieNode {
  vector<shared_ptr<TrieNode>> children;
  bool isWord = false;
  TrieNode() : children(26) {}
};

class MagicDictionary {
 public:
  void buildDict(vector<string> dictionary) {
    for (const string& word : dictionary)
      insert(word);
  }

  bool search(string searchWord) {
    shared_ptr<TrieNode> node = root;
    for (int i = 0; i < searchWord.length(); ++i) {
      const int index = searchWord[i] - 'a';
      for (int j = 0; j < 26; ++j) {
        if (j == index)
          continue;
        shared_ptr<TrieNode> child = node->children[j];
        if (child == nullptr)
          continue;
        // Replace the searchWord[i] with ('a' + j), then check if
        // searchWord[i + 1..n) matches `child`.
        if (find(child, searchWord, i + 1))
          return true;
      }
      if (node->children[index] == nullptr)
        return false;
      node = node->children[index];
    }
    return false;
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
    node->isWord = true;
  }

  bool find(shared_ptr<TrieNode> node, const string& word, int s) {
    for (int i = s; i < word.length(); ++i) {
      const int index = word[i] - 'a';
      if (node->children[index] == nullptr)
        return false;
      node = node->children[index];
    }
    return node->isWord;
  }
};
