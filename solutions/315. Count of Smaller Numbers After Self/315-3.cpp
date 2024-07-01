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
  explicit SegmentTree(const vector<int>& nums)
      : root(build(nums, 0, nums.size() - 1)) {}

  void update(int i, int val) {
    update(root.get(), i, val);
  }

  int query(int i, int j) const {
    return query(root.get(), i, j);
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

  int query(SegmentTreeNode* root, int i, int j) const {
    // [lo, hi] lies completely inside [i, j].
    if (i <= root->lo && root->hi <= j)
      return root->sum;
    // [lo, hi] lies completely outside [i, j].
    if (j < root->lo || root->hi < i)
      return 0;
    return query(root->left, i, j) + query(root->right, i, j);
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
      ans[i] = tree.query(0, ranks[num] - 1);
      tree.update(ranks[num], 1);
    }

    return ans;
  }

 private:
  void getRanks(const vector<int>& nums, unordered_map<int, int>& ranks) {
    set<int> sorted(nums.begin(), nums.end());
    int rank = 0;
    for (const int num : sorted)
      ranks[num] = ++rank;
  }
};
