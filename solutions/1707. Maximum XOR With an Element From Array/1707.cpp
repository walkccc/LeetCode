struct TrieNode {
  vector<shared_ptr<TrieNode>> children;
  TrieNode() : children(2) {}
};

class BitTrie {
 public:
  BitTrie(int maxBit) : maxBit(maxBit) {}

  void insert(int num) {
    shared_ptr<TrieNode> node = root;
    for (int i = maxBit; i >= 0; --i) {
      const int bit = num >> i & 1;
      if (node->children[bit] == nullptr)
        node->children[bit] = make_shared<TrieNode>();
      node = node->children[bit];
    }
  }

  int getMaxXor(int num) {
    int maxXor = 0;
    shared_ptr<TrieNode> node = root;
    for (int i = maxBit; i >= 0; --i) {
      const int bit = num >> i & 1;
      const int toggleBit = bit ^ 1;
      if (node->children[toggleBit] != nullptr) {
        maxXor = maxXor | 1 << i;
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

struct IndexedQuery {
  int queryIndex;
  int x;
  int m;
};

class Solution {
 public:
  vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
    vector<int> ans(queries.size(), -1);
    const int maxNumInNums = ranges::max(nums);
    const int maxNumInQuery =
        ranges::max_element(queries,
                            [](const vector<int>& a, const vector<int>& b) {
      return a[0] < b[0];
    })->at(0);
    const int maxBit = static_cast<int>(log2(max(maxNumInNums, maxNumInQuery)));
    BitTrie bitTrie(maxBit);

    ranges::sort(nums);

    int i = 0;  // nums' index
    for (const auto& [queryIndex, x, m] : getIndexedQueries(queries)) {
      while (i < nums.size() && nums[i] <= m)
        bitTrie.insert(nums[i++]);
      if (i > 0 && nums[i - 1] <= m)
        ans[queryIndex] = bitTrie.getMaxXor(x);
    }

    return ans;
  }

 private:
  vector<IndexedQuery> getIndexedQueries(const vector<vector<int>>& queries) {
    vector<IndexedQuery> indexedQueries;
    for (int i = 0; i < queries.size(); ++i)
      indexedQueries.push_back({i, queries[i][0], queries[i][1]});
    ranges::sort(
        indexedQueries,
        [](const IndexedQuery& a, const IndexedQuery& b) { return a.m < b.m; });
    return indexedQueries;
  }
};
