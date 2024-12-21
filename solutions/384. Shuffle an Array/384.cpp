class Solution {
 public:
  Solution(vector<int>& nums) : nums(std::move(nums)) {}

  /** Resets the array to its original configuration and return it. */
  vector<int> reset() {
    return nums;
  }

  /** Returns a random shuffling of the array. */
  vector<int> shuffle() {
    vector<int> A(nums);
    for (int i = A.size() - 1; i > 0; --i) {
      const int j = rand() % (i + 1);
      swap(A[i], A[j]);
    }
    return A;
  }

 private:
  vector<int> nums;
};
