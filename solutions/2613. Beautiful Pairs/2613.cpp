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
      : n(nums.size()), nums(nums), tree(4 * n, -1) {}

  // Updates the value of the node to be the index of the smaller number
  // between the old value stored at the node and the new value `index`, where
  // `i` is the index of the element in the array that needs to be updated.
  void update(int i, int index) override {
    update(0, 0, n, i, index);
  }

  // Returns the index k s.t. `nums[k]` is the smallest number in nums[i..j].
  int query(int i, int j) override {
    return query(0, 0, n, i, j);
  }

 private:
  const int n;
  const vector<int> nums;  // nums2 + nums1 or nums2 - nums1
  vector<int> tree;        // tree[i] := the maximum index stored in this node

  void update(int treeIndex, int lo, int hi, int i, int index) {
    if (lo == i && hi == i) {
      tree[treeIndex] = merge(tree[treeIndex], index);
      return;
    }
    const int mid = (lo + hi) / 2;
    const int leftTreeIndex = left(treeIndex);
    const int rightTreeIndex = right(treeIndex);
    if (i <= mid)
      update(leftTreeIndex, lo, mid, i, index);
    else
      update(rightTreeIndex, mid + 1, hi, i, index);
    tree[treeIndex] = merge(tree[leftTreeIndex], tree[rightTreeIndex]);
  }

  int query(int treeIndex, int lo, int hi, int i, int j) {
    // [lo, hi] lies completely inside [i, j].
    if (i <= lo && hi <= j)
      return tree[treeIndex];
    // [lo, hi] lies completely outside [i, j].
    if (j < lo || hi < i)
      return -1;
    const int mid = (lo + hi) / 2;
    return merge(query(left(treeIndex), lo, mid, i, j),
                 query(right(treeIndex), mid + 1, hi, i, j));
  }

  // Returns the better index. Index i is better than index j if
  // (nums[i] > nums[j]) or (nums[i] == nums[j] && i < j).
  int merge(int i, int j) override {
    if (i == -1)
      return j;
    if (j == -1)
      return i;
    if (nums[i] > nums[j])
      return i;
    if (nums[j] > nums[i])
      return j;
    return min(i, j);
  }
};

class Solution {
 public:
  vector<int> beautifulPair(vector<int>& nums1, vector<int>& nums2) {
    // The goal is to find the lexicographically smallest beautiful pair (i, j)
    // s.t. |nums1[i] + nums1[j]| + |nums2[i] - nums2[j]| is the smallest.
    //
    // Sort `nums2` and store the order in `indices`.
    // To minimize |nums1[i] - nums1[j]| + |nums2[i] - nums2[j]|, since we
    // already have sorted `nums2`, we can always have nums2[i] > nums2[j] while
    // iterating the array. So we only need to consider the following 2 cases:
    //
    // * nums1[i] >= nums1[j]:
    //   The value will be nums1[i] - nums1[j] + nums2[i] - nums2[j]
    //                   = (nums2[i] + nums1[i]) - (nums2[j] + nums1[j])
    //   Just find max (nums2[j] + nums1[j]) s.t. 0 <= nums1[j] <= nums1[i].
    //
    // * nums1[i] <= nums1[j]:
    //   The value will be nums1[j] - nums1[i] + nums2[i] - nums2[j]
    //                   = (nums2[i] - nums1[i]) - (nums2[j] + nums1[j])
    //   Just find max (nums2[j] - nums1[j]) s.t. nums1[i] <= nums1[j] <= n.
    const int n = nums1.size();
    vector<int> ans(2, n);
    vector<int> nums2PlusNums1;
    vector<int> nums2MinusNums1;
    vector<int> indices;
    int minBeauty = INT_MAX;

    for (int i = 0; i < n; ++i) {
      nums2PlusNums1.push_back(nums2[i] + nums1[i]);
      nums2MinusNums1.push_back(nums2[i] - nums1[i]);
      indices.push_back(i);
    }

    ranges::sort(indices,
                 [&nums2](int i, int j) { return nums2[i] < nums2[j]; });

    SegmentTree tree1(nums2PlusNums1);
    SegmentTree tree2(nums2MinusNums1);

    for (const int i : indices) {
      const int num = nums1[i];
      // For case nums1[i] >= nums1[j], find index j s.t. (nums2[j] + nums1[j])
      // is the maximum in the range [0, nums1[i]].
      int j = tree1.query(0, num);
      if (j >= 0)
        updateAns(nums2PlusNums1, i, j, minBeauty, ans);
      tree1.update(num, i);
      // For case nums1[i] <= nums1[j], find index j s.t. (nums2[j] - nums1[j])
      // is the maximum in the range [nums1[i], n].
      j = tree2.query(num, n);
      if (j >= 0)
        updateAns(nums2MinusNums1, i, j, minBeauty, ans);
      tree2.update(num, i);
    }

    return ans;
  }

 private:
  void updateAns(const vector<int>& nums, int i, int j, int& minBeauty,
                 vector<int>& ans) {
    // beauty := |nums1[i] - nums1[j]| + |nums2[i] - nums2[j]|
    const int beauty = nums[i] - nums[j];
    const vector<int> nextAns = {min(i, j), max(i, j)};
    if (beauty < minBeauty) {
      minBeauty = beauty;
      ans = nextAns;
    } else if (beauty == minBeauty) {
      ans = min(ans, nextAns);
    }
  }
};
