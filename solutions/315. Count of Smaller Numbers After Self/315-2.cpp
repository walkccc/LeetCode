class SegmentTree {
 public:
  explicit SegmentTree(const vector<int>& nums) : n(nums.size()), tree(n * 4) {
    build(nums, 0, 0, n - 1);
  }

  // Adds val to nums[i].
  void add(int i, int val) {
    add(0, 0, n - 1, i, val);
  }

  // Returns sum(nums[i..j]).
  int query(int i, int j) const {
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
    build(nums, 2 * treeIndex + 1, lo, mid);
    build(nums, 2 * treeIndex + 2, mid + 1, hi);
    tree[treeIndex] = merge(tree[2 * treeIndex + 1], tree[2 * treeIndex + 2]);
  }

  void add(int treeIndex, int lo, int hi, int i, int val) {
    if (lo == hi) {
      tree[treeIndex] += val;
      return;
    }
    const int mid = (lo + hi) / 2;
    if (i <= mid)
      add(2 * treeIndex + 1, lo, mid, i, val);
    else
      add(2 * treeIndex + 2, mid + 1, hi, i, val);
    tree[treeIndex] = merge(tree[2 * treeIndex + 1], tree[2 * treeIndex + 2]);
  }

  int query(int treeIndex, int lo, int hi, int i, int j) const {
    if (i <= lo && hi <= j)  // [lo, hi] lies completely inside [i, j].
      return tree[treeIndex];
    if (j < lo || hi < i)  // [lo, hi] lies completely outside [i, j].
      return 0;
    const int mid = (lo + hi) / 2;
    return merge(query(treeIndex * 2 + 1, lo, mid, i, j),
                 query(treeIndex * 2 + 2, mid + 1, hi, i, j));
  }

  int merge(int left, int right) const {
    return left + right;
  }
};

class Solution {
 public:
  vector<int> countSmaller(vector<int>& nums) {
    vector<int> ans(nums.size());
    unordered_map<int, int> ranks;
    getRanks(nums, ranks);
    SegmentTree tree(vector<int>(ranks.size() + 1));

    for (int i = nums.size() - 1; i >= 0; --i) {
      const int num = nums[i];
      ans[i] = tree.query(0, ranks[num] - 1);
      tree.add(ranks[num], 1);
    }

    return ans;
  }

 private:
  void getRanks(const vector<int>& nums, unordered_map<int, int>& ranks) {
    set<int> sorted(nums.begin(), nums.end());
    int rank = 0;
    for (const int num : sorted)
      ranks[num] = ++rank;
  }
};
