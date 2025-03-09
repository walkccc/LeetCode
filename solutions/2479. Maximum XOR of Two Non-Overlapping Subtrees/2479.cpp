struct TrieNode {
  vector<shared_ptr<TrieNode>> children;
  TrieNode() : children(2) {}
};

class BitTrie {
 public:
  BitTrie(int maxBit) : maxBit(maxBit) {}

  void insert(long num) {
    shared_ptr<TrieNode> node = root;
    for (int i = maxBit; i >= 0; --i) {
      const int bit = num >> i & 1;
      if (node->children[bit] == nullptr)
        node->children[bit] = make_shared<TrieNode>();
      node = node->children[bit];
    }
  }

  long getMaxXor(long num) {
    long maxXor = 0;
    shared_ptr<TrieNode> node = root;
    for (int i = maxBit; i >= 0; --i) {
      const int bit = num >> i & 1;
      const int toggleBit = bit ^ 1;
      if (node->children[toggleBit] != nullptr) {
        maxXor = maxXor | 1L << i;
        node = node->children[toggleBit];
      } else if (node->children[bit] != nullptr) {
        node = node->children[bit];
      } else {  // There's nothing in the Bit Trie.
        return 0;
      }
    }
    return maxXor;
  }

 private:
  const int maxBit;
  shared_ptr<TrieNode> root = make_shared<TrieNode>();
};

class Solution {
 public:
  long long maxXor(int n, vector<vector<int>>& edges, vector<int>& values) {
    long ans = 0;
    vector<vector<int>> tree(n);
    vector<long> treeSums(n);

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      tree[u].push_back(v);
      tree[v].push_back(u);
    }

    getTreeSum(tree, 0, -1, treeSums, values);
    const long maxSubTreeSum =
        *max_element(treeSums.begin() + 1, treeSums.end());
    const int maxBit = static_cast<int>(log2(maxSubTreeSum));
    // Similar to 421. Maximum XOR of Two Numbers in an Array
    dfs(tree, 0, -1, treeSums, BitTrie(maxBit), ans);
    return ans;
  }

 private:
  // Gets the tree sum rooted at node u.
  long getTreeSum(const vector<vector<int>>& tree, int u, int prev,
                  vector<long>& treeSums, const vector<int>& values) {
    long treeSum = values[u];
    for (const int v : tree[u])
      if (v != prev)
        treeSum += getTreeSum(tree, v, u, treeSums, values);
    treeSums[u] = treeSum;
    return treeSum;
  }

  void dfs(const vector<vector<int>>& tree, int u, int prev,
           const vector<long>& treeSums, BitTrie&& bitTrie, long& ans) {
    for (const int v : tree[u]) {
      if (v == prev)
        continue;
      // Preorder to get the ans.
      ans = max(ans, bitTrie.getMaxXor(treeSums[v]));
      // Recursively call on the subtree rooted at node v.
      dfs(tree, v, u, treeSums, std::move(bitTrie), ans);
      // Postorder insert the tree sum rooted at node v.
      bitTrie.insert(treeSums[v]);
    }
  }
};
