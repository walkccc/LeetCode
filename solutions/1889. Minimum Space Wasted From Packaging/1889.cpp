class Solution {
 public:
  int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
    constexpr int kMod = 1'000'000'007;
    constexpr long kInf = 1e11;
    const long packagesSum = accumulate(packages.begin(), packages.end(), 0L);
    long minBoxesSum = kInf;

    sort(packages.begin(), packages.end());

    for (vector<int>& box : boxes) {
      sort(box.begin(), box.end());
      if (box.back() < packages.back())
        continue;
      long accu = 0;
      long i = 0;
      for (const int b : box) {
        const long j = firstGreaterEqual(packages, b + 1);
        accu += b * (j - i);
        i = j;
      }
      minBoxesSum = min(minBoxesSum, accu);
    }

    return minBoxesSum == kInf ? -1 : (minBoxesSum - packagesSum) % kMod;
  }

 private:
  int firstGreaterEqual(const vector<int>& A, int target) {
    return lower_bound(A.begin(), A.end(), target) - A.begin();
  }
};
