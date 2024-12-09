class Solution {
 public:
  int maxLength(vector<int>& ribbons, int k) {
    int l = 1;
    int r = accumulate(ribbons.begin(), ribbons.end(), 0L) / k + 1;

    while (l < r) {
      const int m = (l + r) / 2;
      if (!isCutPossible(ribbons, m, k))
        r = m;
      else
        l = m + 1;
    }

    return l - 1;
  }

 private:
  bool isCutPossible(const vector<int>& ribbons, int length, int k) {
    int count = 0;
    for (const int ribbon : ribbons)
      count += ribbon / length;
    return count >= k;
  }
};
