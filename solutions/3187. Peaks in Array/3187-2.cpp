class SegmentTree {
 public:
  explicit SegmentTree(const vector<int>& peak) : n(peak.size()), tree(n * 4) {
    build(peak, 0, 0, n - 1);
  }

  // Updates peak[i] to val.
  void update(int i, int val) {
    update(0, 0, n - 1, i, val);
  }

  // Returns sum(peak[i..j]).
  int query(int i, int j) const {
    return query(0, 0, n - 1, i, j);
  }

 private:
  const int n;       // the size of the input array
  vector<int> tree;  // the segment tree

  void build(const vector<int>& peak, int treeIndex, int lo, int hi) {
    if (lo == hi) {
      tree[treeIndex] = peak[lo];
      return;
    }
    const int mid = (lo + hi) / 2;
    build(peak, 2 * treeIndex + 1, lo, mid);
    build(peak, 2 * treeIndex + 2, mid + 1, hi);
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
  vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
    const vector<int> peak = getPeak(nums);
    vector<int> ans;
    SegmentTree tree(peak);

    for (const vector<int>& query : queries)
      if (query[0] == 1) {
        const int l = query[1];
        const int r = query[2];
        ans.push_back(tree.query(l + 1, r - 1));
      } else if (query[0] == 2) {
        const int index = query[1];
        const int val = query[2];
        nums[index] = val;
        tree.update(index, isPeak(nums, index));
        if (index > 0)
          tree.update(index - 1, isPeak(nums, index - 1));
        if (index + 1 < nums.size())
          tree.update(index + 1, isPeak(nums, index + 1));
      }

    return ans;
  }

 private:
  vector<int> getPeak(const vector<int>& nums) {
    vector<int> peak(nums.size());
    for (int i = 1; i + 1 < nums.size(); ++i)
      peak[i] = nums[i] > nums[i - 1] && nums[i] > nums[i + 1];
    return peak;
  }

  bool isPeak(const vector<int>& nums, int i) {
    return i > 0 && i + 1 < nums.size() && nums[i] > nums[i - 1] &&
           nums[i] > nums[i + 1];
  }
};
