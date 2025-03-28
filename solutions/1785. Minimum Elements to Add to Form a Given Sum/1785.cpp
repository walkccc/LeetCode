class Solution {
 public:
  int minElements(vector<int>& nums, int limit, int goal) {
    const long sum = accumulate(nums.begin(), nums.end(), 0L);
    const double diff = abs(goal - sum);
    return ceil(diff / limit);
  }
};
