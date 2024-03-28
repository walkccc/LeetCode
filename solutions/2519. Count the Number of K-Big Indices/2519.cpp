class FenwickTree {
 public:
  FenwickTree(int n) : sums(n + 1) {}

  void update(int i, int delta) {
    while (i < sums.size()) {
      sums[i] += delta;
      i += lowbit(i);
    }
  }

  int get(int i) const {
    int sum = 0;
    while (i > 0) {
      sum += sums[i];
      i -= lowbit(i);
    }
    return sum;
  }

 private:
  vector<int> sums;

  static inline int lowbit(int i) {
    return i & -i;
  }
};

class Solution {
 public:
  int kBigIndices(vector<int>& nums, int k) {
    const int n = nums.size();
    int ans = 0;
    FenwickTree leftTree(n);
    FenwickTree rightTree(n);
    // left[i] := the number of `nums` < nums[i] with index < i
    vector<int> left(n);
    // right[i] := the number of `nums` < nums[i] with index > i
    vector<int> right(n);

    for (int i = 0; i < n; ++i) {
      left[i] = leftTree.get(nums[i] - 1);
      leftTree.update(nums[i], 1);
    }

    for (int i = n - 1; i >= 0; --i) {
      right[i] = rightTree.get(nums[i] - 1);
      rightTree.update(nums[i], 1);
    }

    for (int i = 0; i < n; ++i)
      if (left[i] >= k && right[i] >= k)
        ++ans;

    return ans;
  }
};
