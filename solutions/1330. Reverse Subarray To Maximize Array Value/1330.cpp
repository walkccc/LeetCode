class Solution {
 public:
  int maxValueAfterReverse(vector<int>& nums) {
    int total = 0;
    int mn = INT_MAX;
    int mx = INT_MIN;

    for (int i = 0; i + 1 < nums.size(); ++i) {
      const int a = nums[i];
      const int b = nums[i + 1];
      total += abs(a - b);
      mn = min(mn, max(a, b));
      mx = max(mx, min(a, b));
    }
    int diff = max(0, (mx - mn) * 2);

    for (int i = 0; i + 1 < nums.size(); ++i) {
      const int a = nums[i];
      const int b = nums[i + 1];
      const int headDiff = -abs(a - b) + abs(nums.front() - b);
      const int tailDiff = -abs(a - b) + abs(nums.back() - a);
      diff = max({diff, headDiff, tailDiff});
    }

    return total + diff;
  }
};
