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
    return max(left, right);
  }
};

class Solution {
 public:
  int maxRectangleArea(vector<vector<int>>& points) {
    int ans = -1;
    ranges::sort(points);
    const vector<int> ys = getUniqueAndSortedYs(points);
    SegmentTree tree(ys.size(), /*kInf=*/-1);
    unordered_map<int, int> yToIndex;
    unordered_map<int, int> yToX;

    for (int i = 0; i < ys.size(); ++i)
      yToIndex[ys[i]] = i;

    int prevX = points[0][0];
    int prevY = points[0][1];

    for (int i = 1; i < points.size(); ++i) {
      const int x = points[i][0];
      const int y = points[i][1];
      if (yToX.contains(prevY) && yToX.contains(y)) {
        const int xLeft = yToX[y];
        if (prevX == x && yToX[prevY] == xLeft &&
            xLeft > tree.query(yToIndex[prevY] + 1, yToIndex[y] - 1))
          ans = max(ans, (y - prevY) * (x - xLeft));
      }
      yToX[prevY] = prevX;
      tree.update(yToIndex[prevY], prevX);
      prevX = x;
      prevY = y;
    }

    return ans;
  }

 private:
  vector<int> getUniqueAndSortedYs(const vector<vector<int>>& points) {
    vector<int> ys;
    for (const vector<int>& point : points)
      ys.push_back(point[1]);
    ranges::sort(ys);
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
    return ys;
  }
};
