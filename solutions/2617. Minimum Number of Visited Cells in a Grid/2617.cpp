class SegmentTree {
 public:
  explicit SegmentTree(int n, int kInf) : kInf(kInf), n(n), tree(4 * n, kInf) {}

  // Updates nums[i] to val.
  void update(int i, int val) {
    update(0, 0, n - 1, i, val);
  }

  // Returns min(nums[i..j]).
  int query(int i, int j) const {
    return query(0, 0, n - 1, i, j);
  }

 private:
  const int kInf;    // the invalid value
  const int n;       // the size of the input array
  vector<int> tree;  // the segment tree

  void update(int treeIndex, int lo, int hi, int i, int val) {
    if (lo == hi) {
      tree[treeIndex] = val;
      return;
    }
    const int mid = (lo + hi) / 2;
    if (i <= mid)
      update(2 * treeIndex + 1, lo, mid, i, val);
    else
      update(2 * treeIndex + 2, mid + 1, hi, i, val);
    tree[treeIndex] = merge(tree[2 * treeIndex + 1], tree[2 * treeIndex + 2]);
  }

  int query(int treeIndex, int lo, int hi, int i, int j) const {
    if (i <= lo && hi <= j)  // [lo, hi] lies completely inside [i, j].
      return tree[treeIndex];
    if (j < lo || hi < i)  // [lo, hi] lies completely outside [i, j].
      return kInf;
    const int mid = (lo + hi) / 2;
    return merge(query(treeIndex * 2 + 1, lo, mid, i, j),
                 query(treeIndex * 2 + 2, mid + 1, hi, i, j));
  }

  int merge(int left, int right) const {
    return min(left, right);
  }
};

class Solution {
 public:
  int minimumVisitedCells(vector<vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    const int kInf = (m + n) * 2 - 1;
    vector<SegmentTree> rows(m, SegmentTree(n, kInf));
    vector<SegmentTree> cols(n, SegmentTree(m, kInf));

    // The min # cells to visit (m - 1, n - 1) from (m - 1, n - 1) is 1.
    rows[m - 1].update(n - 1, 1);
    cols[n - 1].update(m - 1, 1);

    for (int i = m - 1; i >= 0; --i)
      for (int j = n - 1; j >= 0; --j) {
        // There's no k s.t. j < k <= 0 + j.
        // There's no k s.t. i < k <= 0 + i.
        if (grid[i][j] == 0)
          continue;
        const int moveRight = rows[i].query(j + 1, grid[i][j] + j);
        const int moveDown = cols[j].query(i + 1, grid[i][j] + i);
        const int minMove = min(kInf, min(moveRight, moveDown) + 1);
        rows[i].update(j, minMove);
        cols[j].update(i, minMove);
      }

    const int res = rows[0].query(0, 0);
    return res == kInf ? -1 : res;
  }
};
