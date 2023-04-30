class NumArray {
 public:
  NumArray(vector<int>& nums) : prefix(nums.size() + 1) {
    partial_sum(begin(nums), end(nums), begin(prefix) + 1);
  }

  int sumRange(int left, int right) {
    return prefix[right + 1] - prefix[left];
  }

 private:
  vector<int> prefix;
};
