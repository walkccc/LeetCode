struct SegmentTreeNode {
  int lo;
  int hi;
  std::unique_ptr<SegmentTreeNode> left;
  std::unique_ptr<SegmentTreeNode> right;
  int mx;
  long sum;
  SegmentTreeNode(int lo, int hi, std::unique_ptr<SegmentTreeNode>&& left,
                  std::unique_ptr<SegmentTreeNode>&& right, int mx, long sum)
      : lo(lo),
        hi(hi),
        left(std::move(left)),
        right(std::move(right)),
        mx(mx),
        sum(sum) {}
};

class SegmentTree {
 public:
  explicit SegmentTree(int n, int m) : m(m), root(std::move(build(0, n - 1))) {}

  vector<int> maxRange(int k, int maxRow) {
    return maxRange(root, k, maxRow);
  }

  long sumRange(int maxRow) {
    return sumRange(root, 0, maxRow);
  }

  // Substracts k from the seats row.
  void substract(int row, int k) {
    substract(root, row, k);
  }

 private:
  const int m;
  std::unique_ptr<SegmentTreeNode> root;

  std::unique_ptr<SegmentTreeNode> build(int l, int r) {
    if (l == r)
      return make_unique<SegmentTreeNode>(l, r, nullptr, nullptr, m, m);
    const int mid = (l + r) / 2;
    std::unique_ptr<SegmentTreeNode> left = build(l, mid);
    std::unique_ptr<SegmentTreeNode> right = build(mid + 1, r);
    return make_unique<SegmentTreeNode>(l, r, std::move(left), std::move(right),
                                        max(left->mx, right->mx),
                                        left->sum + right->sum);
  }

  vector<int> maxRange(std::unique_ptr<SegmentTreeNode>& root, int k,
                       int maxRow) {
    if (root->lo == root->hi) {
      if (root->sum < k || root->lo > maxRow)
        return {};
      return {root->lo, m - static_cast<int>(root->sum)};  // {row, col}
    }
    // Greedily search the left subtree
    if (root->left->mx >= k)
      return maxRange(root->left, k, maxRow);
    return maxRange(root->right, k, maxRow);
  }

  long sumRange(std::unique_ptr<SegmentTreeNode>& root, int i, int j) {
    if (root->lo == i && root->hi == j)
      return root->sum;
    const int mid = (root->lo + root->hi) / 2;
    if (j <= mid)
      return sumRange(root->left, i, j);
    if (i > mid)
      return sumRange(root->right, i, j);
    return sumRange(root->left, i, mid) + sumRange(root->right, mid + 1, j);
  }

  void substract(std::unique_ptr<SegmentTreeNode>& root, int row, int k) {
    if (root == nullptr)
      return;
    if (root->lo == root->hi && root->hi == row) {
      root->mx -= k;
      root->sum -= k;
      return;
    }
    const int mid = (root->lo + root->hi) / 2;
    if (row <= mid)
      substract(root->left, row, k);
    else
      substract(root->right, row, k);
    root->mx = max(root->left->mx, root->right->mx);
    root->sum = root->left->sum + root->right->sum;
  }
};

class BookMyShow {
 public:
  BookMyShow(int n, int m) : tree(n, m), seats(n, m) {}

  vector<int> gather(int k, int maxRow) {
    const vector<int> res = tree.maxRange(k, maxRow);
    if (res.size() == 2) {
      const int row = res[0];
      tree.substract(row, k);
      seats[row] -= k;
    }
    return res;
  }

  bool scatter(int k, int maxRow) {
    if (tree.sumRange(maxRow) < k)
      return false;

    while (k > 0)
      if (seats[minVacantRow] >= k) {
        tree.substract(minVacantRow, k);
        seats[minVacantRow] -= k;
        k = 0;
      } else {
        tree.substract(minVacantRow, seats[minVacantRow]);
        k -= seats[minVacantRow];
        seats[minVacantRow] = 0;
        ++minVacantRow;
      }

    return true;
  }

 private:
  SegmentTree tree;
  vector<int> seats;  // the remaining seats at each row
  int minVacantRow = 0;
};
