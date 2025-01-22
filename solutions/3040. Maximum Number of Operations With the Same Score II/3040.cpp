class Solution {
 public:
  int maxOperations(vector<int>& nums) {
    const int n = nums.size();
    unordered_map<string, int> mem;
    return max({maxOperations(nums, 0, n - 1, nums[0] + nums[1], mem),
                maxOperations(nums, 0, n - 1, nums[n - 1] + nums[n - 2], mem),
                maxOperations(nums, 0, n - 1, nums[0] + nums[n - 1], mem)});
  }

 private:
  // Returns the maximum number of operations that can be performed for
  // nums[i..j], s.t. all operations have the same `score`.
  int maxOperations(const vector<int>& nums, int i, int j, int score,
                    unordered_map<string, int>& mem) {
    if (i >= j)
      return 0;
    const string key = hash(i, j, score);
    if (const auto it = mem.find(key); it != mem.end())
      return it->second;
    const int deleteFirstTwo =
        nums[i] + nums[i + 1] == score
            ? 1 + maxOperations(nums, i + 2, j, score, mem)
            : 0;
    const int deleteLastTwo =
        nums[j] + nums[j - 1] == score
            ? 1 + maxOperations(nums, i, j - 2, score, mem)
            : 0;
    const int deleteFirstAndLast =
        nums[i] + nums[j] == score
            ? 1 + maxOperations(nums, i + 1, j - 1, score, mem)
            : 0;
    return mem[key] = max({deleteFirstTwo, deleteLastTwo, deleteFirstAndLast});
  }

  string hash(int i, int j, int score) {
    return to_string(i) + "," + to_string(j) + "," + to_string(score);
  }
};
