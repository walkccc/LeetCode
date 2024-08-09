using NodeType = array<array<int, 2>, 2>;

class SegmentTree {
 public:
  explicit SegmentTree(const vector<int>& nums) : n(nums.size()), tree(4 * n) {
    build(nums, 0, 0, n - 1);
  }

  // Updates nums[i] to val.
  void update(int i, int val) {
    update(0, 0, n - 1, i, val);
  }

  // Returns the four values of the range query from nums[i..j].
  //
  // The four values are:
  //   1. nums[i] is not selected, nums[j] is not selected
  //   2. nums[i] is not selected, nums[j] is selected
  //   3. nums[i] is selected, nums[j] is not selected
  //   4. nums[i] is selected, nums[j] is selected
  NodeType query(int i, int j) const {
    return query(0, 0, n - 1, i, j);
  }

 private:
  static constexpr int kInf = 1'000'000'000;
  static constexpr NodeType kDefaultNode = {{{-kInf, -kInf}, {-kInf, -kInf}}};
  const int n;  // the size of the input array
  // tree[i][l][r] := the value of the i-th node, where `l` and `r` represent if
  // the leftmost or rightmost element is selected, respectively
  vector<NodeType> tree;

  void build(const vector<int>& nums, int treeIndex, int lo, int hi) {
    if (lo == hi) {
      tree[treeIndex] = {{{0, -kInf}, {-kInf, nums[lo]}}};
      return;
    }
    const int mid = (lo + hi) / 2;
    build(nums, 2 * treeIndex + 1, lo, mid);
    build(nums, 2 * treeIndex + 2, mid + 1, hi);
    tree[treeIndex] = merge(tree[2 * treeIndex + 1], tree[2 * treeIndex + 2]);
  }

  void update(int treeIndex, int lo, int hi, int i, int val) {
    if (lo == hi) {
      tree[treeIndex] = {{{0, -kInf}, {-kInf, val}}};
      return;
    }
    const int mid = (lo + hi) / 2;
    if (i <= mid)
      update(2 * treeIndex + 1, lo, mid, i, val);
    else
      update(2 * treeIndex + 2, mid + 1, hi, i, val);
    tree[treeIndex] = merge(tree[2 * treeIndex + 1], tree[2 * treeIndex + 2]);
  }

  NodeType query(int treeIndex, int lo, int hi, int i, int j) const {
    if (i <= lo && hi <= j)  // [lo, hi] lies completely inside [i, j].
      return tree[treeIndex];
    if (j < lo || hi < i)  // [lo, hi] lies completely outside [i, j].
      return kDefaultNode;
    const int mid = (lo + hi) / 2;
    return merge(query(2 * treeIndex + 1, lo, mid, i, j),
                 query(2 * treeIndex + 2, mid + 1, hi, i, j));
  }

  // Merges the result of the left node and the right node.
  NodeType merge(const NodeType& a, const NodeType& b) const {
    NodeType node = {{{0, 0}, {0, 0}}};
    for (int l = 0; l < 2; ++l)
      for (int r = 0; r < 2; ++r)
        node[l][r] =
            max({a[l][0] + b[0][r], a[l][0] + b[1][r], a[l][1] + b[0][r]});
    return node;
  }
};

class Solution {
 public:
  int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
    constexpr int kMod = 1'000'000'007;
    const int n = nums.size();
    int ans = 0;
    SegmentTree tree(nums);

    for (const vector<int>& query : queries) {
      const int pos = query[0];
      const int x = query[1];
      tree.update(pos, x);
      NodeType res = tree.query(0, n - 1);
      ans = (ans + static_cast<long>(
                       max({res[0][0], res[0][1], res[1][0], res[1][1]}))) %
            kMod;
    }

    return ans;
  }
};
