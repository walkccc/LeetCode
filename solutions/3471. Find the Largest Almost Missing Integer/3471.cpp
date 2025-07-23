class Solution {
 public:
  int largestInteger(vector<int>& nums, int k) {
    if (k == nums.size())
      return ranges::max(nums);
    const vector<int> count = getCount(nums);
    if (k == 1)
      return maxUnique(nums, count);
    return max(count[nums.front()] == 1 ? nums.front() : -1,
               count[nums.back()] == 1 ? nums.back() : -1);
  }

 private:
  // Returns the maximum unique integer in nums if any. Otherwise, returns -1.
  int maxUnique(const vector<int>& nums, const vector<int>& count) {
    int maxUnique = -1;
    for (const int num : nums)
      if (count[num] == 1)
        maxUnique = max(maxUnique, num);
    return maxUnique;
  }

  vector<int> getCount(const vector<int>& nums) {
    constexpr int kMax = 50;
    vector<int> count(kMax + 1);
    for (const int num : nums)
      ++count[num];
    return count;
  }
};
