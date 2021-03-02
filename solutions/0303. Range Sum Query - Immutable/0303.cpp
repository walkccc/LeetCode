class NumArray {
 public:
  NumArray(vector<int>& nums) : prefix(nums.size() + 1) {
    for (int i = 0; i < nums.size(); ++i)
      prefix[i + 1] += nums[i] + prefix[i];
  }

  int sumRange(int i, int j) {
    return prefix[j + 1] - prefix[i];
  }

 private:
  vector<int> prefix;
};
