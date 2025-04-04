struct TrieNode {
  vector<shared_ptr<TrieNode>> children;
  bool isWord = false;
  TrieNode() : children(10) {}
};

class Trie {
 public:
  void insert(const string& number) {
    shared_ptr<TrieNode> node = root;
    for (const char d : number) {
      const int i = d - '0';
      if (node->children[i] == nullptr)
        node->children[i] = make_shared<TrieNode>();
      node = node->children[i];
    }
    node->isWord = true;
  }

  // Returns true if the number is a prefix of any number in the trie or any
  // number in the trie is a prefix of the number.
  bool search(const string& number) {
    shared_ptr<TrieNode> node = root;
    for (const char d : number) {
      const int i = d - '0';
      if (node->children[i] == nullptr)
        return false;
      node = node->children[i];
      if (node->isWord)
        return true;
    }
    return true;  // The number is a prefix of some number in the trie
  }

 private:
  shared_ptr<TrieNode> root = make_shared<TrieNode>();
};

class Solution {
 public:
  bool phonePrefix(vector<string>& numbers) {
    Trie trie;

    for (const string& number : numbers) {
      if (trie.search(number))
        return false;
      trie.insert(number);
    }

    return true;
  }
};
