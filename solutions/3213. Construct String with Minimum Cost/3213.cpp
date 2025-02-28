class TrieNode {
 public:
  vector<shared_ptr<TrieNode>> children;
  int cost = INT_MAX;
  TrieNode() : children(26) {}
};

class Trie {
 public:
  // Inserts a word with a cost.
  void insert(const string& word, int cost) {
    shared_ptr<TrieNode> node = root;
    for (const char c : word) {
      const int i = c - 'a';
      if (node->children[i] == nullptr)
        node->children[i] = make_shared<TrieNode>();
      node = node->children[i];
    }
    node->cost = min(node->cost, cost);
  }

  // Returns the minimum cost to construct s[i:].
  int search(const string& word, int i, vector<int>& mem) {
    if (i == word.size())
      return 0;
    if (mem[i] != INT_MAX)
      return mem[i];
    int cost = INT_MAX;
    shared_ptr<TrieNode> node = root;
    for (int j = i; j < word.length(); ++j) {
      const int index = word[j] - 'a';
      if (node->children[index] == nullptr)
        break;
      node = node->children[index];
      if (node->cost != INT_MAX) {
        const int childCost = search(word, j + 1, mem);
        if (childCost != INT_MAX)
          cost = min(cost, node->cost + childCost);
      }
    }
    return mem[i] = cost;
  }

 private:
  shared_ptr<TrieNode> root = make_shared<TrieNode>();
};

class Solution {
 public:
  int minimumCost(string target, vector<string>& words, vector<int>& costs) {
    Trie trie;

    for (int i = 0; i < words.size(); ++i)
      trie.insert(words[i], costs[i]);

    vector<int> mem(target.size(), INT_MAX);
    const int ans = trie.search(target, 0, mem);
    return ans == INT_MAX ? -1 : ans;
  }
};
