struct TrieNode {
  vector<shared_ptr<TrieNode>> children;
  bool isWord = false;
  TrieNode() : children(26) {}
};

class Encrypter {
 public:
  Encrypter(vector<char>& keys, vector<string>& values,
            vector<string>& dictionary) {
    for (int i = 0; i < keys.size(); ++i) {
      const char key = keys[i];
      const string& value = values[i];
      keyToValue[key] = value;
      valueToKeys[value].push_back(key);
    }
    for (const string& word : dictionary)
      insert(word);
  }

  string encrypt(string word1) {
    string ans;
    for (const char c : word1)
      ans += keyToValue[c];
    return ans;
  }

  int decrypt(string word2) {
    return find(word2, 0, root);
  }

 private:
  unordered_map<char, string> keyToValue;
  unordered_map<string, vector<char>> valueToKeys;
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

  int find(const string& word, int i, shared_ptr<TrieNode> node) {
    const string value = word.substr(i, 2);
    if (!valueToKeys.contains(value))
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
