struct TrieNode {
  vector<TrieNode*> children;
  int count = 0;
  TrieNode() : children(2) {}
};

class Solution {
 public:
  int countPairs(vector<int>& nums, int low, int high) {
    int ans = 0;

    for (const int num : nums) {
      ans += getCount(num, high + 1) - getCount(num, low);
      insert(num);
    }

    return ans;
  }

 private:
  constexpr static int kHeight = 14;
  TrieNode root;
  void insert(int num) {
    TrieNode* node = &root;
    for (int i = kHeight; i >= 0; --i) {
      const int bit = ((num >> i) & 1);
      if (!node->children[bit])
        node->children[bit] = new TrieNode();
      node = node->children[bit];
      ++node->count;
    }
  }

  // # of nums < limit
  int getCount(int num, int limit) {
    int count = 0;
    TrieNode* node = &root;
    for (int i = kHeight; i >= 0; --i) {
      const int bit = ((num >> i) & 1);
      const int bitLimit = ((limit >> i) & 1);
      if (bitLimit == 1) {
        if (node->children[bit])
          count += node->children[bit]->count;
        node = node->children[bit ^ 1];
      } else {
        node = node->children[bit];
      }
      if (!node)
        break;
    }
    return count;
  }
};
