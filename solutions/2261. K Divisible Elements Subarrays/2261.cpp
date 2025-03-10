struct TrieNode {
  unordered_map<int, shared_ptr<TrieNode>> children;
  int count = 0;
};

class Solution {
 public:
  int countDistinct(vector<int>& nums, int k, int p) {
    int ans = 0;
    for (int i = 0; i < nums.size(); ++i)
      insert(root, nums, i, k, p, ans);
    return ans;
  }

 private:
  shared_ptr<TrieNode> root = make_shared<TrieNode>();

  void insert(shared_ptr<TrieNode> node, const vector<int>& nums, int i, int k,
              int p, int& ans) {
    if (i == nums.size() || k - (nums[i] % p == 0) < 0)
      return;
    if (!node->children.contains(nums[i])) {
      node->children[nums[i]] = make_shared<TrieNode>();
      ++ans;
    }
    insert(node->children[nums[i]], nums, i + 1, k - (nums[i] % p == 0), p,
           ans);
  }
};
