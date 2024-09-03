struct TrieNode {
  vector<shared_ptr<TrieNode>> children;
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
  static constexpr int kHeight = 14;
  shared_ptr<TrieNode> root = make_shared<TrieNode>();

  void insert(int num) {
    shared_ptr<TrieNode> node = root;
    for (int i = kHeight; i >= 0; --i) {
      const int bit = num >> i & 1;
      if (node->children[bit] == nullptr)
        node->children[bit] = make_shared<TrieNode>();
      node = node->children[bit];
      ++node->count;
    }
  }

  // Returns the number of numbers < limit.
  int getCount(int num, int limit) {
    int count = 0;
    shared_ptr<TrieNode> node = root;
    for (int i = kHeight; i >= 0; --i) {
      const int bit = num >> i & 1;
      const int bitLimit = limit >> i & 1;
      if (bitLimit == 1) {
        if (node->children[bit] != nullptr)
          count += node->children[bit]->count;
        node = node->children[bit ^ 1];
      } else {
        node = node->children[bit];
      }
      if (node == nullptr)
        break;
    }
    return count;
  }
};
