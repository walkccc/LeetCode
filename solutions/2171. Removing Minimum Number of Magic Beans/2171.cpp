class Solution {
 public:
  long long minimumRemoval(vector<int>& beans) {
    const long n = beans.size();
    const long sum = accumulate(begin(beans), end(beans), 0L);
    long ans = LONG_MAX;

    sort(begin(beans), end(beans));

    for (int i = 0; i < n; ++i)
      ans = min(ans, sum - (n - i) * beans[i]);

    return ans;
  }
};
