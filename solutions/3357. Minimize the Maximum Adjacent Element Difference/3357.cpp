class Solution {
 public:
  int minDifference(vector<int>& nums) {
    int maxPositiveGap = 0;
    int mn = 1'000'000'000;
    int mx = 0;

    for (int i = 1; i < nums.size(); ++i)
      if ((nums[i - 1] == -1) != (nums[i] == -1)) {
        const int positive = max(nums[i - 1], nums[i]);
        mn = min(mn, positive);
        mx = max(mx, positive);
      } else {
        maxPositiveGap = max(maxPositiveGap, abs(nums[i - 1] - nums[i]));
      }

    int l = maxPositiveGap;
    int r = (mx - mn + 1) / 2;

    while (l < r) {
      const int m = (l + r) / 2;
      if (check(nums, m, mn + m, mx - m))
        r = m;
      else
        l = m + 1;
    }

    return l;
  }

 private:
  // Returns true if it's possible have `m` as maximum absolute difference
  // between adjacent numbers, where -1s are replaced with `x` or `y`.
  bool check(const vector<int>& nums, int m, int x, int y) {
    int gapLength = 0;
    int prev = 0;

    for (const int num : nums) {
      if (num == -1) {
        ++gapLength;
        continue;
      }
      if (prev > 0 && gapLength > 0) {
        if (gapLength == 1 && !checkSingleGap(prev, num, m, x, y))
          return false;
        if (gapLength > 1 && !checkMultipleGaps(prev, num, m, x, y))
          return false;
      }
      prev = num;
      gapLength = 0;
    }

    // Check leading gaps.
    if (nums[0] == -1) {
      const int num = findFirstNumber(nums, 0, 1);
      if (num != -1 && !checkBoundaryGaps(num, m, x, y))
        return false;
    }

    // Check trailing gaps.
    if (nums.back() == -1) {
      const int num = findFirstNumber(nums, nums.size() - 1, -1);
      if (num != -1 && !checkBoundaryGaps(num, m, x, y))
        return false;
    }

    return true;
  }

  // Returns true if it's possible to have at most `m` as the minimized maximum
  // difference for a sequence with a single -1 between two numbers.
  // e.g. [a, -1, b] can be filled with either x or y.
  bool checkSingleGap(int a, int b, int m, int x, int y) {
    const int gapWithX = max(abs(a - x), abs(b - x));  // [a, x, b]
    const int gapWithY = max(abs(a - y), abs(b - y));  // [a, y, b]
    return min(gapWithX, gapWithY) <= m;
  }

  // Returns true if it's possible to have at most `m` as the minimized maximum
  // difference for a sequence with multiple -1s between two numbers.
  // e.g. [a, -1, -1, ..., -1, b] can be filled with x and y.
  bool checkMultipleGaps(int a, int b, int m, int x, int y) {
    const int ax = abs(a - x);
    const int ay = abs(a - y);
    const int bx = abs(b - x);
    const int by = abs(b - y);
    const int xy = abs(x - y);
    const int gapAllX = max(ax, bx);        // [a, x, x, ..., x, b]
    const int gapAllY = max(ay, by);        // [a, y, y, ..., y, b]
    const int gapXToY = max({ax, xy, by});  // [a, x, ..., y, b]
    const int gapYToX = max({ay, xy, bx});  // [a, y, ..., x, b]
    return min({gapAllX, gapAllY, gapXToY, gapYToX}) <= m;
  }

  // Returns true if it's possible to have at most `m` as the minimized maximum
  // difference for a boundary sequence starting or ending with -1s.
  // e.g. [a, -1, -1, ...] or [..., -1, -1, a].
  bool checkBoundaryGaps(int a, int m, int x, int y) {
    const int gapAllX = abs(a - x);  // [x, x, ..., x, a]
    const int gapAllY = abs(a - y);  // [y, y, ..., y, a]
    return min(gapAllX, gapAllY) <= m;
  }

  // Returns the first positive number starting from the given index or -1
  // if not found.
  int findFirstNumber(const vector<int>& nums, int start, int step) {
    int i = start;
    while (i >= 0 && i < nums.size() && nums[i] == -1)
      i += step;
    return i >= 0 && i < nums.size() ? nums[i] : -1;
  }
};
