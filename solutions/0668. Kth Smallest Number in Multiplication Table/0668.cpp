class Solution {
 public:
  int findKthNumber(int m, int n, int k) {
    int l = 1;
    int r = m * n;

    auto numsNoGreaterThan = [&](int target) {
      int count = 0;
      // for each row i, count numbers that are no greater than m
      for (int i = 1; i <= m; ++i)
        count += min(target / i, n);
      return count;
    };

    while (l < r) {
      const int mid = l + (r - l) / 2;
      if (numsNoGreaterThan(mid) < k)
        l = mid + 1;
      else
        r = mid;
    }

    return l;
  }
};