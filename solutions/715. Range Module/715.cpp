struct SegmentTreeNode {
  int lo;
  int hi;
  bool tracked = false;
  SegmentTreeNode* left;
  SegmentTreeNode* right;
  SegmentTreeNode(int lo, int hi, bool tracked, SegmentTreeNode* left = nullptr,
                  SegmentTreeNode* right = nullptr)
      : lo(lo), hi(hi), tracked(tracked), left(left), right(right) {}
  ~SegmentTreeNode() {
    delete left;
    delete right;
    left = nullptr;
    right = nullptr;
  }
};

class SegmentTree {
 public:
  explicit SegmentTree() : root(make_unique<SegmentTreeNode>(0, 1e9, false)) {}

  void addRange(int i, int j) {
    update(root.get(), i, j, true);
  }

  bool queryRange(int i, int j) {
    return query(root.get(), i, j);
  }

  void removeRange(int i, int j) {
    update(root.get(), i, j, false);
  }

 private:
  std::unique_ptr<SegmentTreeNode> root;

  void update(SegmentTreeNode* root, int i, int j, bool tracked) {
    if (root->lo == i && root->hi == j) {
      root->tracked = tracked;
      root->left = nullptr;
      root->right = nullptr;
      return;
    }
    const int mid = root->lo + (root->hi - root->lo) / 2;
    if (root->left == nullptr) {
      root->left = new SegmentTreeNode(root->lo, mid, root->tracked);
      root->right = new SegmentTreeNode(mid + 1, root->hi, root->tracked);
    }
    if (j <= mid)
      update(root->left, i, j, tracked);
    else if (i > mid)
      update(root->right, i, j, tracked);
    else {
      update(root->left, i, mid, tracked);
      update(root->right, mid + 1, j, tracked);
    }
    root->tracked = root->left->tracked && root->right->tracked;
  }

  bool query(SegmentTreeNode* root, int i, int j) {
    if (root->left == nullptr)
      return root->tracked;
    if (root->lo == i && root->hi == j)
      return root->tracked;
    const int mid = root->lo + (root->hi - root->lo) / 2;
    if (j <= mid)
      return query(root->left, i, j);
    if (i > mid)
      return query(root->right, i, j);
    return query(root->left, i, mid) && query(root->right, mid + 1, j);
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
