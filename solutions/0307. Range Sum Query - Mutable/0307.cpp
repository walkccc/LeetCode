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

class NumArray {
 public:
  NumArray(vector<int>& nums) : nums(nums), tree(nums.size()) {
    for (int i = 0; i < nums.size(); ++i)
      tree.update(i + 1, nums[i]);
  }

  void update(int index, int val) {
    tree.update(index + 1, val - nums[index]);
    nums[index] = val;
  }

  int sumRange(int left, int right) {
    return tree.get(right + 1) - tree.get(left);
  }

 private:
  vector<int> nums;
  FenwickTree tree;
};
