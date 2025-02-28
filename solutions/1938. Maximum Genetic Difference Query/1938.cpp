struct TrieNode {
  vector<shared_ptr<TrieNode>> children;
  int count = 0;
  TrieNode() : children(2) {}
};

class Trie {
 public:
  void update(int num, int val) {
    shared_ptr<TrieNode> node = root;
    for (int i = kHeight; i >= 0; --i) {
      const int bit = (num >> i) & 1;
      if (node->children[bit] == nullptr)
        node->children[bit] = make_shared<TrieNode>();
      node = node->children[bit];
      node->count += val;
    }
  }

  int query(int num) {
    int ans = 0;
    shared_ptr<TrieNode> node = root;
    for (int i = kHeight; i >= 0; --i) {
      const int bit = (num >> i) & 1;
      const int targetBit = bit ^ 1;
      if (node->children[targetBit] && node->children[targetBit]->count) {
        ans += 1 << i;
        node = node->children[targetBit];
      } else {
        node = node->children[targetBit ^ 1];
      }
    }
    return ans;
  }

 private:
  static constexpr int kHeight = 17;
  shared_ptr<TrieNode> root = make_shared<TrieNode>();
};

class Solution {
 public:
  vector<int> maxGeneticDifference(vector<int>& parents,
                                   vector<vector<int>>& queries) {
    const int n = parents.size();
    vector<int> ans(queries.size());
    int rootVal = -1;
    vector<vector<int>> tree(n);
    // {node: (index, val)}
    unordered_map<int, vector<pair<int, int>>> nodeToQueries;
    Trie trie;

    for (int i = 0; i < parents.size(); ++i)
      if (parents[i] == -1)
        rootVal = i;
      else
        tree[parents[i]].push_back(i);

    for (int i = 0; i < queries.size(); ++i) {
      const int node = queries[i][0];
      const int val = queries[i][1];
      nodeToQueries[node].emplace_back(i, val);
    }

    dfs(rootVal, trie, tree, nodeToQueries, ans);
    return ans;
  }

 private:
  void dfs(int node, Trie& trie, const vector<vector<int>>& tree,
           const unordered_map<int, vector<pair<int, int>>>& nodeToQueries,
           vector<int>& ans) {
    trie.update(node, 1);

    if (const auto it = nodeToQueries.find(node); it != nodeToQueries.cend())
      for (const auto& [i, val] : it->second)
        ans[i] = trie.query(val);

    for (const int child : tree[node])
      dfs(child, trie, tree, nodeToQueries, ans);

    trie.update(node, -1);
  }
};
