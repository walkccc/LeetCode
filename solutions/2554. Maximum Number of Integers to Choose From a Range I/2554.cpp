class Solution {
 public:
  int maxCount(vector<int>& banned, int n, int maxSum) {
    int ans = 0;
    int sum = 0;
    const unordered_set<int> bannedSet{banned.begin(), banned.end()};

    for (int i = 1; i <= n; ++i)
      if (!bannedSet.count(i) && sum + i <= maxSum) {
        ++ans;
        sum += i;
      }

    return ans;
  }
};
