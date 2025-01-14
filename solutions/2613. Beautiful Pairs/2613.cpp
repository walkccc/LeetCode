class SegmentTree {
 public:
  explicit SegmentTree(const vector<int>& nums)
      : maxNum(nums.size()), nums(std::move(nums)), tree(4 * maxNum, -1) {}

  // Updates the value of the node to be the index of the smaller number between
  // the old value stored at the node and the new value `index`, where `i` is
  // the index of the element in the `nums` array.
  void update(int i, int numIndex) {
    update(0, 0, maxNum, i, numIndex);
  }

  // Returns the index k s.t. `nums[k]` is maximum number in the range [i, j].
  int query(int i, int j) const {
    return query(0, 0, maxNum, i, j);
  }

 private:
  // default node value for non-overlapping queries
  static constexpr int kDefaultValue = -1;
  const int maxNum;
  const vector<int> nums;  // nums2 + nums1 or nums2 - nums1
  vector<int> tree;        // tree[i] := the minimum index stored in this node

  void update(int treeIndex, int lo, int hi, int i, int numIndex) {
    if (lo == hi) {
      tree[treeIndex] = merge(tree[treeIndex], numIndex);
      return;
    }
    const int mid = (lo + hi) / 2;
    if (i <= mid)
      update(2 * treeIndex + 1, lo, mid, i, numIndex);
    else
      update(2 * treeIndex + 2, mid + 1, hi, i, numIndex);
    tree[treeIndex] = merge(tree[2 * treeIndex + 1], tree[2 * treeIndex + 2]);
  }

  int query(int treeIndex, int lo, int hi, int i, int j) const {
    if (i <= lo && hi <= j)  // [lo, hi] lies completely inside [i, j].
      return tree[treeIndex];
    if (j < lo || hi < i)  // [lo, hi] lies completely outside [i, j].
      return kDefaultValue;
    const int mid = (lo + hi) / 2;
    return merge(query(2 * treeIndex + 1, lo, mid, i, j),
                 query(2 * treeIndex + 2, mid + 1, hi, i, j));
  }

  // Returns the better index. Index i is better than index j if
  // (nums[i] > nums[j]) or (nums[i] == nums[j] && i < j).
  int merge(const int& i, const int& j) const {
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
    // s.t. |nums1[i] - nums1[j]| + |nums2[i] - nums2[j]| is the smallest.
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
    //                   = (nums2[i] - nums1[i]) - (nums2[j] - nums1[j])
    //   Just find max (nums2[j] - nums1[j]) s.t. nums1[i] <= nums1[j] <= n.
    constexpr int kInf = 1'000'000'000;
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
