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

  void add(int i, int val) {
    add(root.get(), i, val);
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
    auto left = build(nums, lo, mid);
    auto right = build(nums, mid + 1, hi);
    return new SegmentTreeNode(lo, hi, left->sum + right->sum, left, right);
  }

  void add(SegmentTreeNode* root, int i, int val) {
    if (root->lo == i && root->hi == i) {
      root->sum += val;
      return;
    }
    const int mid = (root->lo + root->hi) / 2;
    if (i <= mid)
      add(root->left, i, val);
    else
      add(root->right, i, val);
    root->sum = root->left->sum + root->right->sum;
  }

  int query(SegmentTreeNode* root, int i, int j) const {
    if (root->lo == i && root->hi == j)
      return root->sum;
    const int mid = (root->lo + root->hi) / 2;
    if (j <= mid)
      return query(root->left, i, j);
    if (i > mid)
      return query(root->right, i, j);
    return merge(query(root->left, i, mid), query(root->right, mid + 1, j));
  }

  int merge(int left, int right) const {
    return left + right;
  }
};

class Solution {
 public:
  int reversePairs(vector<int>& nums) {
    int ans = 0;
    const unordered_map<long, int> ranks = getRanks(nums);
    SegmentTree tree(vector<int>(ranks.size() + 1));

    for (int i = nums.size() - 1; i >= 0; --i) {
      const long num = nums[i];
      ans += tree.query(0, ranks.at(num) - 1);
      tree.add(ranks.at(num * 2), 1);
    }

    return ans;
  }

 private:
  unordered_map<long, int> getRanks(const vector<int>& nums) {
    unordered_map<long, int> ranks;
    set<long> sorted(nums.begin(), nums.end());
    for (const long num : nums)
      sorted.insert(num * 2);
    int rank = 0;
    for (const long num : sorted)
      ranks[num] = ++rank;
    return ranks;
  }
};
