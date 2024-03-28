template <typename T>
class RangeQuery {
 public:
  virtual void update(int index, int val);
  virtual T query(int i, int j);

 private:
  virtual T merge(T a, T b);

 protected:
  int left(int treeIndex) {
    return 2 * treeIndex + 1;
  }

  int right(int treeIndex) {
    return 2 * treeIndex + 2;
  }
};

class SegmentTree : RangeQuery<int> {
 public:
  explicit SegmentTree(const vector<int>& nums)
      : n(nums.size()), tree(nums.size() * 4) {
    build(nums, 0, 0, n - 1);
  }

  // Updates nums[i] to val equivalently.
  void update(int i, int val) override {
    update(0, 0, n - 1, i, val);
  }

  // Returns sum(nums[i..j]).
  int query(int i, int j) override {
    return query(0, 0, n - 1, i, j);
  }

 private:
  const int n;       // the size of the input array
  vector<int> tree;  // the segment tree

  void build(const vector<int>& nums, int treeIndex, int lo, int hi) {
    if (lo == hi) {
      tree[treeIndex] = nums[lo];
      return;
    }
    const int mid = (lo + hi) / 2;
    const int leftTreeIndex = left(treeIndex);
    const int rightTreeIndex = right(treeIndex);
    build(nums, leftTreeIndex, lo, mid);
    build(nums, rightTreeIndex, mid + 1, hi);
    tree[treeIndex] = merge(tree[leftTreeIndex], tree[rightTreeIndex]);
  }

  void update(int treeIndex, int lo, int hi, int i, int val) {
    if (lo == i && hi == i) {
      tree[treeIndex] = val;
      return;
    }
    const int mid = (lo + hi) / 2;
    const int leftTreeIndex = left(treeIndex);
    const int rightTreeIndex = right(treeIndex);
    if (i <= mid)
      update(leftTreeIndex, lo, mid, i, val);
    else
      update(rightTreeIndex, mid + 1, hi, i, val);
    tree[treeIndex] = merge(tree[leftTreeIndex], tree[rightTreeIndex]);
  }

  int query(int treeIndex, int lo, int hi, int i, int j) {
    // [lo, hi] lies completely inside [i, j].
    if (i <= lo && hi <= j)
      return tree[treeIndex];
    // [lo, hi] lies completely outside [i, j].
    if (j < lo || hi < i)
      return 0;
    const int mid = (lo + hi) / 2;
    return merge(query(left(treeIndex), lo, mid, i, j),
                 query(right(treeIndex), mid + 1, hi, i, j));
  }

  // Merges the result of the left node and the right node.
  int merge(int a, int b) override {
    return a + b;
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
