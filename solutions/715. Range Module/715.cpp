struct SegmentTreeNode {
  int lo;
  int hi;
  bool tracked = false;
  std::unique_ptr<SegmentTreeNode> left;
  std::unique_ptr<SegmentTreeNode> right;
  SegmentTreeNode(int lo, int hi, bool tracked,
                  std::unique_ptr<SegmentTreeNode> left = nullptr,
                  std::unique_ptr<SegmentTreeNode> right = nullptr)
      : lo(lo),
        hi(hi),
        tracked(tracked),
        left(std::move(left)),
        right(std::move(right)) {}
};

class SegmentTree {
 public:
  explicit SegmentTree() : root(make_unique<SegmentTreeNode>(0, 1e9, false)) {}

  void addRange(int i, int j) {
    update(root, i, j, true);
  }

  bool queryRange(int i, int j) {
    return query(root, i, j);
  }

  void removeRange(int i, int j) {
    update(root, i, j, false);
  }

 private:
  std::unique_ptr<SegmentTreeNode> root;

  void update(std::unique_ptr<SegmentTreeNode>& root, int i, int j,
              bool tracked) {
    if (root->lo == i && root->hi == j) {
      root->tracked = tracked;
      root->left = nullptr;
      root->right = nullptr;
      return;
    }
    const int mid = root->lo + (root->hi - root->lo) / 2;
    if (root->left == nullptr) {
      root->left = make_unique<SegmentTreeNode>(root->lo, mid, root->tracked);
      root->right =
          make_unique<SegmentTreeNode>(mid + 1, root->hi, root->tracked);
    }
    if (j <= mid)
      update(root->left, i, j, tracked);
    else if (i > mid)
      update(root->right, i, j, tracked);
    else {
      update(root->left, i, mid, tracked);
      update(root->right, mid + 1, j, tracked);
    }
    root->tracked = merge(root->left->tracked, root->right->tracked);
  }

  bool query(std::unique_ptr<SegmentTreeNode>& root, int i, int j) const {
    if (root->left == nullptr)
      return root->tracked;
    if (root->lo == i && root->hi == j)
      return root->tracked;
    const int mid = root->lo + (root->hi - root->lo) / 2;
    if (j <= mid)
      return query(root->left, i, j);
    if (i > mid)
      return query(root->right, i, j);
    return merge(query(root->left, i, mid), query(root->right, mid + 1, j));
  }

  bool merge(bool left, bool right) const {
    return left && right;
  }
};

class RangeModule {
 public:
  void addRange(int left, int right) {
    tree.addRange(left, right - 1);
  }

  bool queryRange(int left, int right) {
    return tree.queryRange(left, right - 1);
  }

  void removeRange(int left, int right) {
    tree.removeRange(left, right - 1);
  }

 private:
  SegmentTree tree;
};
