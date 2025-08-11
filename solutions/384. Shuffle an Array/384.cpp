class Solution {
 public:
  Solution(vector<int>& nums) : nums(std::move(nums)) {}

  vector<int> reset() {
    return nums;
  }

  vector<int> shuffle() {
    vector<int> arr(nums);
    for (int i = arr.size() - 1; i > 0; --i) {
      const int j = rand() % (i + 1);
      swap(arr[i], arr[j]);
    }
    return arr;
  }

 private:
  vector<int> nums;
};
