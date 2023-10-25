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
      } else {  // Nothing in the Bit Trie.
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
  vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
    vector<int> ans(queries.size(), -1);
    vector<pair<vector<int>, int>> queryAndIndexes;

    const int maxNumInNums = ranges::max(nums);
    const int maxNumInQuery =
        ranges::max_element(queries,
                            [](const vector<int>& a, const vector<int>& b) {
      return a[0] < b[0];
    })->at(0);
    const int maxBit = static_cast<int>(log2(max(maxNumInNums, maxNumInQuery)));
    BitTrie bitTrie(maxBit);

    for (int i = 0; i < queries.size(); i++)
      queryAndIndexes.emplace_back(queries[i], i);

    ranges::sort(nums);
    ranges::sort(queryAndIndexes, [](const pair<vector<int>, int>& a,
                                     const pair<vector<int>, int>& b) {
      return a.first[1] < b.first[1];
    });

    int i = 0;  // nums' index
    for (const auto& [query, index] : queryAndIndexes) {
      const int x = query[0];
      const int m = query[1];
      while (i < nums.size() && nums[i] <= m)
        bitTrie.insert(nums[i++]);
      if (i > 0 && nums[i - 1] <= m)
        ans[index] = bitTrie.getMaxXor(x);
    }

    return ans;
  }
};
