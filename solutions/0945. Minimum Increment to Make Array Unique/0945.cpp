class Solution {
 public:
  int minIncrementForUnique(vector<int>& nums) {
    int ans = 0;
    int minAvailable = 0;

    sort(begin(nums), end(nums));

    for (const int num : nums) {
      ans += max(minAvailable - num, 0);
      minAvailable = max(minAvailable, num) + 1;
    }

    return ans;
  }
};
