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
      : n(nums.size()), tree(nums.size() * 4) {}

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

  void update(int treeIndex, int lo, int hi, int i, int val) {
    if (lo == i && hi == i) {
      tree[treeIndex] += val;
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

class Solution {
 public:
  int reversePairs(vector<int>& nums) {
    int ans = 0;
    unordered_map<long, int> ranks;
    getRanks(nums, ranks);
    SegmentTree tree(vector<int>(ranks.size() + 1));

    for (int i = nums.size() - 1; i >= 0; --i) {
      const long num = nums[i];
      ans += tree.query(0, ranks[num] - 1);
      tree.update(ranks[num * 2], 1);
    }

    return ans;
  }

 private:
  void getRanks(const vector<int>& nums, unordered_map<long, int>& ranks) {
    set<long> sorted(nums.begin(), nums.end());
    for (const long num : nums)
      sorted.insert(num * 2);
    int rank = 0;
    for (const long num : sorted)
      ranks[num] = ++rank;
  }
};
