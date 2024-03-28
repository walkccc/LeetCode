class Solution {
 public:
  int maxValueAfterReverse(vector<int>& nums) {
    int total = 0;
    int min = INT_MAX;
    int max = INT_MIN;

    for (int i = 0; i + 1 < nums.size(); ++i) {
      int a = nums[i];
      int b = nums[i + 1];
      total += abs(a - b);
      min = std::min(min, std::max(a, b));
      max = std::max(max, std::min(a, b));
    }
    int diff = std::max(0, (max - min) * 2);

    for (int i = 0; i + 1 < nums.size(); ++i) {
      int a = nums[i];
      int b = nums[i + 1];
      int headDiff = -abs(a - b) + abs(nums.front() - b);
      int tailDiff = -abs(a - b) + abs(nums.back() - a);
      diff = std::max({diff, headDiff, tailDiff});
    }

    return total + diff;
  }
};
