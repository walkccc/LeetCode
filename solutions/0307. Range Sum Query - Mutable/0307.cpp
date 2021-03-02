class FenwickTree {
 public:
  FenwickTree(int n) : sums(n + 1) {}

  void update(int i, int delta) {
    while (i < sums.size()) {
      sums[i] += delta;
      i += i & -i;
    }
  }

  int get(int i) {
    int sum = 0;
    while (i > 0) {
      sum += sums[i];
      i -= i & -i;
    }
    return sum;
  }

 private:
  vector<int> sums;
};

class NumArray {
 public:
  NumArray(vector<int>& nums) : nums(nums), tree(nums.size()) {
    for (int i = 0; i < nums.size(); ++i)
      tree.update(i + 1, nums[i]);
  }

  void update(int i, int val) {
    tree.update(i + 1, val - nums[i]);
    nums[i] = val;
  }

  int sumRange(int i, int j) {
    return tree.get(j + 1) - tree.get(i);
  }

 private:
  vector<int> nums;
  FenwickTree tree;
};
