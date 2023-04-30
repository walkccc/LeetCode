class Solution {
 public:
  int flipgame(vector<int>& fronts, vector<int>& backs) {
    int ans = 2001;
    unordered_set<int> same;

    for (int i = 0; i < fronts.size(); ++i)
      if (fronts[i] == backs[i])
        same.insert(fronts[i]);

    for (const int f : fronts)
      if (!same.count(f))
        ans = min(ans, f);

    for (const int b : backs)
      if (!same.count(b))
        ans = min(ans, b);

    return ans == 2001 ? 0 : ans;
  }
};
