class Solution {
 public:
  int flipgame(vector<int>& fronts, vector<int>& backs) {
    constexpr int kMax = 2001;
    int ans = kMax;
    unordered_set<int> same;

    for (int i = 0; i < fronts.size(); ++i)
      if (fronts[i] == backs[i])
        same.insert(fronts[i]);

    for (const int front : fronts)
      if (!same.contains(front))
        ans = min(ans, front);

    for (const int back : backs)
      if (!same.contains(back))
        ans = min(ans, back);

    return ans == kMax ? 0 : ans;
  }
};
