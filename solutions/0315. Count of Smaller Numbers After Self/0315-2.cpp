struct SegmentTreeNode {
  int lo;
  int hi;
  int sum;
  SegmentTreeNode* left;
  SegmentTreeNode* right;
  SegmentTreeNode(int lo, int hi, int sum, SegmentTreeNode* left = nullptr,
                  SegmentTreeNode* right = nullptr)
      : lo(lo), hi(hi), sum(sum), left(left), right(right) {}
  ~SegmentTreeNode() {
    delete left;
    delete right;
    left = nullptr;
    right = nullptr;
  }
};

class SegmentTree {
 public:
  SegmentTree(const vector<int>& nums)
      : root(build(nums, 0, nums.size() - 1)) {}

  void update(int i, int val) {
    update(root.get(), i, val);
  }

  int sumRange(int i, int j) const {
    return sumRange(root.get(), i, j);
  }

 private:
  std::unique_ptr<SegmentTreeNode> root;

  SegmentTreeNode* build(const vector<int>& nums, int lo, int hi) const {
    if (lo == hi)
      return new SegmentTreeNode(lo, hi, nums[lo]);
    const int mid = (lo + hi) / 2;
    SegmentTreeNode* left = build(nums, lo, mid);
    SegmentTreeNode* right = build(nums, mid + 1, hi);
    return new SegmentTreeNode(lo, hi, left->sum + right->sum, left, right);
  }

  void update(SegmentTreeNode* root, int i, int val) {
    if (root->lo == i && root->hi == i) {
      root->sum += val;
      return;
    }
    const int mid = (root->lo + root->hi) / 2;
    if (i <= mid)
      update(root->left, i, val);
    else
      update(root->right, i, val);
    root->sum = root->left->sum + root->right->sum;
  }

  int sumRange(SegmentTreeNode* root, int i, int j) const {
    if (root->lo == i && root->hi == j)
      return root->sum;
    const int mid = (root->lo + root->hi) / 2;
    if (j <= mid)
      return sumRange(root->left, i, j);
    if (i > mid)
      return sumRange(root->right, i, j);
    return sumRange(root->left, i, mid) + sumRange(root->right, mid + 1, j);
  }
};

class Solution {
 public:
  vector<int> countSmaller(vector<int>& nums) {
    vector<int> ans(nums.size());
    unordered_map<int, int> ranks;
    getRanks(nums, ranks);
    SegmentTree tree(vector<int>(ranks.size() + 1));

    for (int i = nums.size() - 1; i >= 0; --i) {
      const int num = nums[i];
      ans[i] = tree.sumRange(0, ranks[num] - 1);
      tree.update(ranks[num], 1);
    }

    return ans;
  }

 private:
  void getRanks(const vector<int>& nums, unordered_map<int, int>& ranks) {
    set<int> sorted(begin(nums), end(nums));
    int rank = 0;
    for (const int num : sorted)
      ranks[num] = ++rank;
  }
};
