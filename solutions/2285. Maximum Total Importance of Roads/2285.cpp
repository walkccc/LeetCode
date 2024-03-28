class Solution {
 public:
  long long maximumImportance(int n, vector<vector<int>>& roads) {
    long long ans = 0;
    vector<long long> count(n);

    for (const vector<int>& r : roads) {
      ++count[r[0]];
      ++count[r[1]];
    }

    ranges::sort(count);

    for (int i = 0; i < n; ++i)
      ans += (i + 1) * count[i];

    return ans;
  }
};
