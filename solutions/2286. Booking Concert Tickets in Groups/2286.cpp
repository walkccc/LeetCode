struct SegmentTreeNode {
  int lo;
  int hi;
  unique_ptr<SegmentTreeNode> left;
  unique_ptr<SegmentTreeNode> right;
  int max;
  long sum;
  SegmentTreeNode(int lo, int hi, unique_ptr<SegmentTreeNode>&& left,
                  unique_ptr<SegmentTreeNode>&& right, int max, long sum)
      : lo(lo),
        hi(hi),
        left(move(left)),
        right(move(right)),
        max(max),
        sum(sum) {}
};

class SegmentTree {
 public:
  SegmentTree(int n, int m) : m(m), root(move(build(0, n - 1))) {}

  vector<int> maxRange(int k, int maxRow) {
    return maxRange(root, k, maxRow);
  }

  long sumRange(int maxRow) {
    return sumRange(root, 0, maxRow);
  }

  // minus k max and sum from seats row
  void minus(int row, int k) {
    minus(root, row, k);
  }

 private:
  const int m;
  unique_ptr<SegmentTreeNode> root;

  unique_ptr<SegmentTreeNode> build(int l, int r) {
    if (l == r)
      return make_unique<SegmentTreeNode>(l, r, nullptr, nullptr, m, m);
    const int mid = (l + r) / 2;
    unique_ptr<SegmentTreeNode> left = build(l, mid);
    unique_ptr<SegmentTreeNode> right = build(mid + 1, r);
    return make_unique<SegmentTreeNode>(l, r, move(left), move(right),
                                        max(left->max, right->max),
                                        left->sum + right->sum);
  }

  vector<int> maxRange(unique_ptr<SegmentTreeNode>& root, int k, int maxRow) {
    if (root->lo == root->hi) {
      if (root->sum < k || root->lo > maxRow)
        return {};
      return {root->lo, m - static_cast<int>(root->sum)};  // {row, col}
    }
    // greedily search the left subtree
    if (root->left->max >= k)
      return maxRange(root->left, k, maxRow);
    return maxRange(root->right, k, maxRow);
  }

  long sumRange(unique_ptr<SegmentTreeNode>& root, int i, int j) {
    if (root->lo == i && root->hi == j)
      return root->sum;
    const int mid = (root->lo + root->hi) / 2;
    if (j <= mid)
      return sumRange(root->left, i, j);
    if (i > mid)
      return sumRange(root->right, i, j);
    return sumRange(root->left, i, mid) + sumRange(root->right, mid + 1, j);
  }

  void minus(unique_ptr<SegmentTreeNode>& root, int row, int k) {
    if (!root)
      return;
    if (root->lo == root->hi && root->hi == row) {
      root->max -= k;
      root->sum -= k;
      return;
    }
    const int mid = (root->lo + root->hi) / 2;
    if (row <= mid)
      minus(root->left, row, k);
    else
      minus(root->right, row, k);
    root->max = max(root->left->max, root->right->max);
    root->sum = root->left->sum + root->right->sum;
  }
};

class BookMyShow {
 public:
  BookMyShow(int n, int m) : tree(n, m), seats(n, m) {}

  vector<int> gather(int k, int maxRow) {
    const auto res = tree.maxRange(k, maxRow);
    if (res.size() == 2) {
      const int row = res[0];
      tree.minus(row, k);
      seats[row] -= k;
    }
    return res;
  }

  bool scatter(int k, int maxRow) {
    if (tree.sumRange(maxRow) < k)
      return false;

    while (k > 0)
      if (seats[minVacantRow] >= k) {
        tree.minus(minVacantRow, k);
        seats[minVacantRow] -= k;
        k = 0;
      } else {
        tree.minus(minVacantRow, seats[minVacantRow]);
        k -= seats[minVacantRow];
        seats[minVacantRow] = 0;
        ++minVacantRow;
      }

    return true;
  }

 private:
  SegmentTree tree;
  vector<int> seats;  // remain seats at each row
  int minVacantRow = 0;
};
