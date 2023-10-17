struct TrieNode {
  vector<shared_ptr<TrieNode>> children;
  bool isWord = false;
  TrieNode() : children(26) {}
};

class StreamChecker {
 public:
  StreamChecker(vector<string>& words) {
    for (const string& word : words)
      insert(word);
  }

  bool query(char letter) {
    letters += letter;
    shared_ptr<TrieNode> node = root;

    for (int i = letters.length() - 1; i >= 0; --i) {
      const int index = letters[i] - 'a';
      if (node->children[index] == nullptr)
        return false;
      node = node->children[index];
      if (node->isWord)
        return true;
    }

    return false;
  }

 private:
  shared_ptr<TrieNode> root = make_shared<TrieNode>();
  string letters;

  void insert(const string& word) {
    shared_ptr<TrieNode> node = root;
    for (int i = word.length() - 1; i >= 0; --i) {
      const int index = word[i] - 'a';
      if (node->children[index] == nullptr)
        node->children[index] = make_shared<TrieNode>();
      node = node->children[index];
    }
    node->isWord = true;
  }
};
