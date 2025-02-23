class Solution {
 public:
  int maxCount(vector<int>& banned, int n, long long maxSum) {
    const unordered_set<int> bannedSet{banned.begin(), banned.end()};
    int l = 1;
    int r = n;

    while (l < r) {
      const int m = (l + r + 1) / 2;
      if (getSum(bannedSet, m) > maxSum)
        r = m - 1;
      else
        l = m;
    }

    return l - ranges::count_if(bannedSet, [l](const int b) { return b <= l; });
  }

 private:
  // Returns sum([1..m]) - sum(bannedSet).
  long getSum(const unordered_set<int>& bannedSet, long m) {
    long sum = m * (m + 1) / 2;  // sum([1..m])
    for (const int b : bannedSet)
      if (b <= m)
        sum -= b;
    return sum;
  }
};
