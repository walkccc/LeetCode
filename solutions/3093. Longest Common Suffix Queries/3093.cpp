struct TrieNode {
  vector<shared_ptr<TrieNode>> children;
  TrieNode() : children(26) {}
  int length = INT_MAX;
  int index = -1;
};

class Solution {
 public:
  vector<int> stringIndices(vector<string>& wordsContainer,
                            vector<string>& wordsQuery) {
    vector<int> ans;
    int minIndex = 0;

    for (int i = 0; i < wordsContainer.size(); ++i) {
      insert(wordsContainer[i], i);
      if (wordsContainer[i].length() < wordsContainer[minIndex].length())
        minIndex = i;
    }

    for (const string& query : wordsQuery) {
      const int index = search(query);
      ans.push_back(index == -1 ? minIndex : index);
    }

    return ans;
  }

 private:
  shared_ptr<TrieNode> root = make_shared<TrieNode>();

  void insert(const string& word, int index) {
    shared_ptr<TrieNode> node = root;
    for (int i = word.length() - 1; i >= 0; --i) {
      const int j = word[i] - 'a';
      if (node->children[j] == nullptr)
        node->children[j] = make_shared<TrieNode>();
      node = node->children[j];
      if (node->length > word.length()) {
        node->length = word.length();
        node->index = index;
      }
    }
  }

  int search(const string& word) {
    shared_ptr<TrieNode> node = root;
    for (int i = word.length() - 1; i >= 0; --i) {
      const int j = word[i] - 'a';
      if (node->children[j] == nullptr)
        return node->index;
      node = node->children[j];
    }
    return node->index;
  }
};
