struct TrieNode {
  vector<shared_ptr<TrieNode>> children;
  const string* word = nullptr;
  TrieNode() : children(26) {}
};

class Solution {
 public:
  string replaceWords(vector<string>& dictionary, string sentence) {
    for (const string& word : dictionary)
      insert(word);

    string ans;
    istringstream iss(sentence);

    for (string s; iss >> s;)
      ans += search(s) + ' ';
    ans.pop_back();

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
    }
    node->word = &word;
  }

  string search(const string& word) {
    shared_ptr<TrieNode> node = root;
    for (const char c : word) {
      if (node->word)
        return *node->word;
      const int i = c - 'a';
      if (node->children[i] == nullptr)
        return word;
      node = node->children[i];
    }
    return word;
  }
};
