struct TrieNode {
  vector<TrieNode*> children;
  bool isWord = false;
  TrieNode() : children(26) {}
  ~TrieNode() {
    for (TrieNode* child : children)
      delete child;
  }
};

class Encrypter {
 public:
  Encrypter(vector<char>& keys, vector<string>& values,
            vector<string>& dictionary) {
    for (int i = 0; i < keys.size(); ++i) {
      const auto& key = keys[i];
      const auto& value = values[i];
      keyToValue[key] = value;
      valueToKeys[value].push_back(key);
    }
    for (const auto& word : dictionary)
      insert(word);
  }

  string encrypt(string word1) {
    string ans;
    for (const char c : word1)
      ans += keyToValue[c];
    return ans;
  }

  int decrypt(string word2) {
    return find(word2, 0, &root);
  }

 private:
  unordered_map<char, string> keyToValue;
  unordered_map<string, vector<char>> valueToKeys;
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

  int find(const string& word, int i, TrieNode* node) {
    const string value = word.substr(i, 2);
    if (!valueToKeys.count(value))
      return 0;

    int ans = 0;
    if (i + 2 == word.length()) {
      for (const char key : valueToKeys[value]) {
        const auto& child = node->children[key - 'a'];
        ans += child && child->isWord;
      }
      return ans;
    }

    for (const char key : valueToKeys[value]) {
      if (!node->children[key - 'a'])
        continue;
      ans += find(word, i + 2, node->children[key - 'a']);
    }

    return ans;
  }
};
