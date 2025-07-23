class Solution {
 public:
  int maximumLength(vector<int>& nums) {
    const int maxNum = ranges::max(nums);
    unordered_map<int, int> count;

    for (const int num : nums)
      ++count[num];

    int ans = count.contains(1) ? count[1] - (count[1] % 2 == 0) : 1;

    for (const int num : nums) {
      if (num == 1)
        continue;
      int length = 0;
      long x = num;
      while (x <= maxNum && count.contains(x) && count[x] >= 2) {
        length += 2;
        x *= x;
      }
      // x is now x^k, and the pattern is [x, ..., x^(k/2), x^(k/2), ..., x].
      // The goal is to determine if we can insert x^k in the middle of the
      // pattern to increase the length by 1. If not, we make x^(k/2) the middle
      // and decrease the length by 1.
      ans = max(ans, length + (count.contains(x) ? 1 : -1));
    }

    return ans;
  }
};
