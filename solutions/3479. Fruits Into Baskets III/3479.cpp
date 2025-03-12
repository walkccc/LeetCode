class SegmentTree {
 public:
  explicit SegmentTree(const vector<int>& nums) : n(nums.size()), tree(n * 4) {
    build(nums, 0, 0, n - 1);
  }

  // Updates nums[i] to val.
  void update(int i, int val) {
    update(0, 0, n - 1, i, val);
  }

  // Returns the first index i where baskets[i] >= target, or -1 if not found.
  int queryFirst(int target) {
    return queryFirst(0, 0, n - 1, target);
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
    build(nums, 2 * treeIndex + 1, lo, mid);
    build(nums, 2 * treeIndex + 2, mid + 1, hi);
    tree[treeIndex] = merge(tree[2 * treeIndex + 1], tree[2 * treeIndex + 2]);
  }

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

  int queryFirst(int treeIndex, int lo, int hi, int target) {
    if (tree[treeIndex] < target)
      return -1;
    if (lo == hi) {
      // Found a valid position, mark it as used by setting to -1.
      update(lo, -1);
      return lo;
    }
    const int mid = (lo + hi) / 2;
    const int leftChild = tree[2 * treeIndex + 1];
    return leftChild >= target
               ? queryFirst(2 * treeIndex + 1, lo, mid, target)
               : queryFirst(2 * treeIndex + 2, mid + 1, hi, target);
  }

  int merge(int left, int right) const {
    return max(left, right);
  }
};

class Solution {
 public:
  // Same as 3477. Fruits Into Baskets II
  int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
    int ans = 0;
    SegmentTree tree(baskets);

    for (const int fruit : fruits)
      if (tree.queryFirst(fruit) == -1)
        ++ans;

    return ans;
  }
};
