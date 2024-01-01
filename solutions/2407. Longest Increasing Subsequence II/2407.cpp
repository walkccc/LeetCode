struct SegmentTreeNode {
  int lo;
  int hi;
  int maxLength;
  unique_ptr<SegmentTreeNode> left;
  unique_ptr<SegmentTreeNode> right;
  // maxLength := the maximum length of LIS ending in [lo..hi]
  SegmentTreeNode(int lo, int hi, int maxLength,
                  unique_ptr<SegmentTreeNode> left = nullptr,
                  unique_ptr<SegmentTreeNode> right = nullptr)
      : lo(lo),
        hi(hi),
        maxLength(maxLength),
        left(move(left)),
        right(move(right)) {}
};

class SegmentTree {
 public:
  explicit SegmentTree() : root(make_unique<SegmentTreeNode>(0, 1e5 + 1, 0)) {}

  void updateRange(int i, int j, int maxLength) {
    update(root, i, j, maxLength);
  }

  // queryRange(i, j) := the maximum length of LIS ending in [i..j]
  int queryRange(int i, int j) {
    return query(root, i, j);
  }

 private:
  std::unique_ptr<SegmentTreeNode> root;

  void update(unique_ptr<SegmentTreeNode>& root, int i, int j, int maxLength) {
    if (root->lo == i && root->hi == j) {
      root->maxLength = maxLength;
      root->left = nullptr;
      root->right = nullptr;
      return;
    }
    const int mid = root->lo + (root->hi - root->lo) / 2;
    if (root->left == nullptr) {
      root->left = make_unique<SegmentTreeNode>(root->lo, mid, root->maxLength);
      root->right =
          make_unique<SegmentTreeNode>(mid + 1, root->hi, root->maxLength);
    }
    if (j <= mid)
      update(root->left, i, j, maxLength);
    else if (i > mid)
      update(root->right, i, j, maxLength);
    else {
      update(root->left, i, mid, maxLength);
      update(root->right, mid + 1, j, maxLength);
    }
    root->maxLength = max(root->left->maxLength, root->right->maxLength);
  }

  int query(unique_ptr<SegmentTreeNode>& root, int i, int j) {
    if (root->left == nullptr)
      return root->maxLength;
    if (root->lo == i && root->hi == j)
      return root->maxLength;
    const int mid = root->lo + (root->hi - root->lo) / 2;
    if (j <= mid)
      return query(root->left, i, j);
    if (i > mid)
      return query(root->right, i, j);
    return max(query(root->left, i, mid), query(root->right, mid + 1, j));
  }
};

class Solution {
 public:
  int lengthOfLIS(vector<int>& nums, int k) {
    int ans = 1;
    SegmentTree tree;

    for (const int num : nums) {
      const int left = max(1, num - k);
      const int right = num - 1;
      // the maximum length of LIS ending in [left..right] + the current number
      const int maxLength = tree.queryRange(left, right) + 1;
      ans = std::max(ans, maxLength);
      tree.updateRange(num, num, maxLength);
    }

    return ans;
  }
};
