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

class Solution {
 public:
  int findMaximumXOR(vector<int>& nums) {
    const int maxNum = ranges::max(nums);
    if (maxNum == 0)
      return 0;
    const int maxBit = static_cast<int>(log2(maxNum));
    int ans = 0;
    BitTrie bitTrie(maxBit);

    for (const int num : nums) {
      ans = max(ans, bitTrie.getMaxXor(num));
      bitTrie.insert(num);
    }

    return ans;
  }
};
