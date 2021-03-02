struct TrieNode {
  TrieNode() : children(26), word(nullptr) {}
  ~TrieNode() {
    for (TrieNode* child : children)
      delete (child);
  }
  vector<TrieNode*> children;
  const string* word;
};

class Solution {
 public:
  string replaceWords(vector<string>& dict, string sentence) {
    for (const string& word : dict)
      insert(word);

    string ans;
    istringstream iss(sentence);

    for (string s; iss >> s;)
      ans += search(s) + ' ';
    ans.pop_back();

    return ans;
  }

 private:
  TrieNode root;

  void insert(const string& word) {
    TrieNode* node = &root;
    for (const char c : word) {
      if (!node->children[c - 'a'])
        node->children[c - 'a'] = new TrieNode;
      node = node->children[c - 'a'];
    }
    node->word = &word;
  }

  string search(const string& word) {
    TrieNode* node = &root;
    for (const char c : word) {
      if (node->word)
        return *node->word;
      if (!node->children[c - 'a'])
        return word;
      node = node->children[c - 'a'];
    }
    return word;
  }
};
