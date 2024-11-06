template <typename NodeType, typename ValueType>
class SegmentTree {
 public:
  explicit SegmentTree(const int n, const NodeType& defaultNode)
      : n(n), defaultNode(defaultNode), tree(4 * n) {}

  // Adds nums[i] to val equivalently.
  void add(int i, ValueType val) {
    add(0, 0, n - 1, i, val);
  }

  // Returns the result of the range query from nums[i..j].
  NodeType query(int i, int j) const {
    return query(0, 0, n - 1, i, j);
  }

 protected:
  // Merges the result of the left node and the right node.
  virtual NodeType merge(const NodeType& a, const NodeType& b) const = 0;
  virtual NodeType makeLeafNode(ValueType val) const = 0;

 private:
  const int n;                 // the size of the input array
  const NodeType defaultNode;  // default node value for non-overlapping queries
  vector<NodeType> tree;       // the segment tree

  void add(int treeIndex, int lo, int hi, int i, ValueType val) {
    if (lo == hi) {
      tree[treeIndex] += makeLeafNode(val);
      return;
    }
    const int mid = (lo + hi) / 2;
    if (i <= mid)
      add(left(treeIndex), lo, mid, i, val);
    else
      add(right(treeIndex), mid + 1, hi, i, val);
    tree[treeIndex] = merge(tree[left(treeIndex)], tree[right(treeIndex)]);
  }

  NodeType query(int treeIndex, int lo, int hi, int i, int j) const {
    if (i <= lo && hi <= j)  // [lo, hi] lies completely inside [i, j].
      return tree[treeIndex];
    if (j < lo || hi < i)  // [lo, hi] lies completely outside [i, j].
      return defaultNode;
    const int mid = (lo + hi) / 2;
    return merge(query(left(treeIndex), lo, mid, i, j),
                 query(right(treeIndex), mid + 1, hi, i, j));
  }

  int left(int treeIndex) const {
    return 2 * treeIndex + 1;
  }

  int right(int treeIndex) const {
    return 2 * treeIndex + 2;
  }
};

class SumSegmentTree : public SegmentTree<int, int> {
 public:
  explicit SumSegmentTree(int n) : SegmentTree(n, 0) {}

 protected:
  int merge(const int& a, const int& b) const override {
    return a + b;
  }

  int makeLeafNode(int val) const override {
    return val;
  }
};

class Solution {
 public:
  int createSortedArray(vector<int>& instructions) {
    constexpr int kMod = 1'000'000'007;
    const int mx = ranges::max(instructions);
    int ans = 0;
    SumSegmentTree tree(mx + 1);

    for (const int i : instructions) {
      ans += min(tree.query(0, i - 1), tree.query(i + 1, mx));
      ans %= kMod;
      tree.add(i, 1);
    }

    return ans;
  }
};
