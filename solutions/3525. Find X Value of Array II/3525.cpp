struct Node {
  int remain[5] = {0};
  int prod = 1;
};

class SegmentTree {
 public:
  explicit SegmentTree(const vector<int>& nums, int k)
      : n(nums.size()), k(k), tree(4 * n) {
    build(nums, 0, 0, n - 1);
  }

  // Updates nums[i] to val.
  void update(int i, int val) {
    update(0, 0, n - 1, i, val);
  }

  // Returns the result of the range query from nums[i..j].
  Node query(int i, int j) const {
    return query(0, 0, n - 1, i, j);
  }

 private:
  const int n;        // the size of the input array
  const int k;        // the modulo value
  vector<Node> tree;  // the segment tree

  void build(const vector<int>& nums, int cur, int left, int right) {
    if (left == right) {
      tree[cur].remain[nums[left]] = 1;
      tree[cur].prod = nums[left];
      return;
    }
    const int mid = (left + right) / 2;
    build(nums, 2 * cur + 1, left, mid);
    build(nums, 2 * cur + 2, mid + 1, right);
    tree[cur] = merge(tree[2 * cur + 1], tree[2 * cur + 2]);
  }

  void update(int treeIndex, int lo, int hi, int i, int val) {
    if (lo == hi) {
      for (int j = 0; j < k; ++j)
        tree[treeIndex].remain[j] = 0;
      tree[treeIndex].remain[val] = 1;
      tree[treeIndex].prod = val;
      return;
    }
    const int mid = (lo + hi) / 2;
    if (i <= mid)
      update(2 * treeIndex + 1, lo, mid, i, val);
    else
      update(2 * treeIndex + 2, mid + 1, hi, i, val);
    tree[treeIndex] = merge(tree[2 * treeIndex + 1], tree[2 * treeIndex + 2]);
  }

  Node query(int treeIndex, int lo, int hi, int i, int j) const {
    if (i <= lo && hi <= j)  // [lo, hi] lies completely inside [i, j].
      return tree[treeIndex];
    if (j < lo || hi < i)  // [lo, hi] lies completely outside [i, j].
      return Node();
    const int mid = (lo + hi) / 2;
    return merge(query(2 * treeIndex + 1, lo, mid, i, j),
                 query(2 * treeIndex + 2, mid + 1, hi, i, j));
  }

  Node merge(const Node& left, const Node& right) const {
    Node node;
    node.prod = (left.prod * right.prod) % k;
    for (int i = 0; i < k; ++i)
      node.remain[i] = left.remain[i];
    for (int i = 0; i < k; ++i)
      node.remain[(i * left.prod) % k] += right.remain[i];
    return node;
  }
};

class Solution {
 public:
  vector<int> resultArray(vector<int>& nums, int k,
                          vector<vector<int>>& queries) {
    for (int& num : nums)
      num %= k;

    for (vector<int>& query : queries)
      query[1] %= k;

    const int n = nums.size();
    vector<int> ans;
    SegmentTree tree(nums, k);

    for (const vector<int>& query : queries) {
      const int index = query[0];
      const int value = query[1];
      const int start = query[2];
      const int x = query[3];
      tree.update(index, value);
      ans.push_back(tree.query(start, n - 1).remain[x]);
    }

    return ans;
  }
};
