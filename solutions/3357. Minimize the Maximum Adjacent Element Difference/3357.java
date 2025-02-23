class Solution {
  public int minDifference(int[] nums) {
    int maxPositiveGap = 0;
    int mn = 1_000_000_000;
    int mx = 0;

    for (int i = 1; i < nums.length; ++i) {
      if ((nums[i - 1] == -1) != (nums[i] == -1)) {
        final int positive = Math.max(nums[i - 1], nums[i]);
        mn = Math.min(mn, positive);
        mx = Math.max(mx, positive);
      } else {
        maxPositiveGap = Math.max(maxPositiveGap, Math.abs(nums[i - 1] - nums[i]));
      }
    }

    int l = maxPositiveGap;
    int r = (mx - mn + 1) / 2;

    while (l < r) {
      final int m = (l + r) / 2;
      if (check(nums, m, mn + m, mx - m))
        r = m;
      else
        l = m + 1;
    }

    return l;
  }

  // Returns true if it's possible have `m` as maximum absolute difference
  // between adjacent numbers, where -1s are replaced with `x` or `y`.
  private boolean check(int[] nums, int m, int x, int y) {
    int gapLength = 0;
    int prev = 0;

    for (final int num : nums) {
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

    // Check leading gaps
    if (nums[0] == -1) {
      final int num = findFirstNumber(nums, 0, 1);
      if (num != -1 && !checkBoundaryGaps(num, m, x, y))
        return false;
    }

    // Check trailing gaps
    if (nums[nums.length - 1] == -1) {
      final int num = findFirstNumber(nums, nums.length - 1, -1);
      if (num != -1 && !checkBoundaryGaps(num, m, x, y))
        return false;
    }

    return true;
  }

  // Returns true if it's possible to have at most `m` as the minimized maximum
  // difference for a sequence with a single -1 between two numbers.
  // e.g. [a, -1, b] can be filled with either x or y.
  private boolean checkSingleGap(int a, int b, int m, int x, int y) {
    final int gapWithX = Math.max(Math.abs(a - x), Math.abs(b - x)); // [a, x, b]
    final int gapWithY = Math.max(Math.abs(a - y), Math.abs(b - y)); // [a, y, b]
    return Math.min(gapWithX, gapWithY) <= m;
  }

  // Returns true if it's possible to have at most `m` as the minimized maximum
  // difference for a sequence with multiple -1s between two numbers.
  // e.g. [a, -1, -1, ..., -1, b] can be filled with x and y.
  private boolean checkMultipleGaps(int a, int b, int m, int x, int y) {
    final int ax = Math.abs(a - x);
    final int ay = Math.abs(a - y);
    final int bx = Math.abs(b - x);
    final int by = Math.abs(b - y);
    final int xy = Math.abs(x - y);
    final int gapAllX = Math.max(ax, bx);               // [a, x, x, ..., x, b]
    final int gapAllY = Math.max(ay, by);               // [a, y, y, ..., y, b]
    final int gapXToY = Math.max(Math.max(ax, xy), by); // [a, x, ..., y, b]
    final int gapYToX = Math.max(Math.max(ay, xy), bx); // [a, y, ..., x, b]
    return Math.min(Math.min(gapAllX, gapAllY), Math.min(gapXToY, gapYToX)) <= m;
  }

  // Returns true if it's possible to have at most `m` as the minimized maximum
  // difference for a boundary sequence starting or ending with -1s.
  // e.g. [a, -1, -1, ...] or [..., -1, -1, a].
  private boolean checkBoundaryGaps(int a, int m, int x, int y) {
    final int gapAllX = Math.abs(a - x); // [x, x, ..., x, a]
    final int gapAllY = Math.abs(a - y); // [y, y, ..., y, a]
    return Math.min(gapAllX, gapAllY) <= m;
  }

  // Returns the first positive number starting from the given index or -1
  // if not found.
  private int findFirstNumber(int[] nums, int start, int step) {
    int i = start;
    while (i >= 0 && i < nums.length && nums[i] == -1)
      i += step;
    return i >= 0 && i < nums.length ? nums[i] : -1;
  }
}
