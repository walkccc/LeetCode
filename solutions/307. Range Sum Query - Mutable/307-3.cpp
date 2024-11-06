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
      root->sum = val;
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
    return merge(query(root->left, i, j), query(root->right, i, j));
  }

  int merge(int left, int right) const {
    return left + right;
  }
};

class NumArray {
 public:
  NumArray(vector<int>& nums) : tree(nums) {}

  void update(int index, int val) {
    tree.update(index, val);
  }

  int sumRange(int left, int right) {
    return tree.query(left, right);
  }

 private:
  SegmentTree tree;
};
